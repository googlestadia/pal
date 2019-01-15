/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2015-2019 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
 ***********************************************************************************************************************
 * @file  palPrivateScreen.h
 * @brief Defines the Platform Abstraction Library (PAL) IPrivateScreen interface and related types.
 ***********************************************************************************************************************
 */

#pragma once

#include "palLib.h"
#include "palScreen.h"

namespace Pal
{

// Forward declarations.
class IFence;
class IImage;
class IPrivateScreen;

/// Maximum number of private screens per device.
constexpr uint32 MaxPrivateScreens      = 6;
/// Maximum number of images can be created on private screen.
constexpr uint32 MaxPrivateScreenImages = 16;
/// Maximum size of edid in bytes.
constexpr uint32 MaxEdidSize            = 512;

/// Maximum number of display bridge.
constexpr uint32 MaxDisplayBridgeIdSize = 16;

/// Specifies event type used for private screen notifications.
enum class PrivateScreenEvent : uint32
{
    TopologyChanged = 0, ///< Indicates the topology is changed, i.e. private screen connectivity is changed (both plug
                         ///  and unplug).
};

/// Specifies private screen type
enum class PrivateScreenType : uint32
{
    Permanent = 0,  ///< Registered to base driver as permanent, automatically hidden at boot time.
    Temporary = 1,  ///< Hidden temporarily, turning into a public screen when it is unhidden or OS reboots.
    Emulated  = 2,  ///< Emulated without actually screen hardware connected, for testing purpose.
};

/// Capability flags of private screen
union PrivateScreenCaps
{
    struct
    {
        uint32 hasAudio : 1;    ///< The private screen has audio support.
        uint32 reserved : 31;   ///< Reserved for future use.
    };
    uint32 u32All;   ///< Caps bits packed in a 32-bit uint.
};

/// Specifies the private screen properties.
struct PrivateScreenProperties
{
    Extent2d          extent;              ///< Width and height of the resolution.
    uint32            targetId;            ///< For a physical private screen, this is an id generated by base driver
                                           ///  and report to application to hide/show dynamically.
                                           ///  For an emulated one, this is a magic number generated by PAL, starting
                                           ///  from 0xFFFFFFFF to be different enough from real target ids.
    PrivateScreenType type;                ///< Type @ref PrivateScreenType.
    Rational          refreshRate;         ///< Refresh rate in Hz.
    uint64            hash;                ///< Hash code based on EDID.
    uint32            edidSize;            ///< Size of EDID in bytes.
    uint8             edid[MaxEdidSize];   ///< EDID of the attached monitor.
    uint32            numFormats;          ///< Number of supported pixel formats.
    SwizzledFormat*   pFormats;            ///< Pointer to supported pixel formats.
    uint32            maxNumPowerSwitches; ///< Maximum number of power switches per frame for fine-grain power mgmt.
    uint32            powerSwitchLatency;  ///< Power switch latency in microseconds.
    PrivateScreenCaps caps;                ///< Capability flags.
};

/// Specified data needed to create a PrivateScreen object.
struct PrivateScreenCreateInfo
{
    uint32                  index;       ///< Screen index, unused for emulated private screen.
    PrivateScreenProperties props;       ///< Screen properties visible to clients.
};

/// Specifies the private screen present statistics.
struct PrivateScreenPresentStats
{
    uint64 presentCount;            ///< Number of present calls on the screen.
    uint64 presentCpuTime;          ///< QPC time of the last present call, close to the time new scan-out address was
                                    ///  sent to GPU.
    uint64 vsyncCount;              ///< Number of Vsync intervals.
    uint64 vsyncCpuTime;            ///< QPC time of the last Vsync interrupt.
    uint64 displayLatchedCpuTime;   ///< QPC time when scan-out surface address was latched by the GPU. In case of Vsync
                                    ///  present it is the same or close to the Vsync interrupt time. For immediate
                                    ///  present it is the time of last Hsync before returning from present.
    uint64 vsyncGpuTime;            ///< GPU timestamp of the last Vsync interrupt.
};

/// Specifies the private screen present information.
struct PrivateScreenPresentInfo
{
    IImage* pSrcImg;           ///< Present source image.
    IFence* pPresentDoneFence; ///< Fence for present done.
    bool    vsync;             ///< Indicates this is a vsync present or not.
};

/// Specifies the private screen enable info.
struct PrivateScreenEnableInfo
{
    union
    {
        struct
        {
            uint32 vsyncAlwaysOn          : 1;  ///< Vsync is always on.
            uint32 disablePowerManagement : 1;  ///< Disable power management on this screen.
            uint32 reserved               : 30; ///< Reserved.
        };
        uint32 u32All;                          ///< Flags packed as 32-bit uint.
    } flags;                                    ///< Private screen enable flags.
};

/// Specifies the private screen bridge info. The concept of a bridge isn't tied to private displays. The idea is that
/// besides plugging display directy into GPU, you can also plug it in through a dongle that converts, for example,
/// DP to HDMI. Other options are various display hubs. All of these intermediate devices are display bridges.
struct PrivateScreenBridge
{
    uint32 bridgeType;                  ///< The type could be hub or some kind of dongle, it it defined
                                        ///  in CONNECTION_BRIDGE_TYPE structure of kdx_umd.h file.
    uint8  id[MaxDisplayBridgeIdSize];  ///< The ID of any such bridge device is some string or set of bytes that DAL
                                        ///  queries from it.
};

/// Specifies the private screen connector properties.
struct PrivateScreenConnectorProperties
{
    uint32               connectorType; ///< The type could be VGA, DVI, HDMI, DP etc.
    uint32               bridgeCount;   ///< The number of bridge.You can have 0 bridges - display is plugged in
                                        ///  directly into GPU, 1 when you connect through a dongle or a hub, or
                                        ///  you can have more than 1 when you connect through a chain of hubs.
    PrivateScreenBridge* pBridge;       ///< The pointer to PrivateScreenBridge
};

/// Specifies the private display timing.
struct PrivateDisplayTiming
{
    uint32 active;               ///< Active timing area in pixels or lines.
    uint32 blank;                ///< Blank period in pixels or lines.
    uint32 syncOffset;           ///< Sync front porch location in pixels or lines.
    uint32 syncWidth;            ///< Sync width in pixels or lines.
    bool   positiveSyncPolarity; ///< Polarity of the sync, true represents positive and false represents negative.
};

/// Specifies the color depth in bits per channel to be sent to display.
enum class PrivateDisplayColorDepth : uint32
{
    ColorDepth666       = 0,    ///< Per channel of color depth is 6 bits.
    ColorDepth888       = 1,    ///< Per channel of color depth is 8 bits.
    ColorDepth101010    = 2,    ///< Per channel of color depth is 10 bits.
};

/// Specifies the color pixel encoding for sending information to the display.
enum class PrivateDisplayPixelEncoding : uint32
{
    Rgb         = 0,    ///< Color format.
    YcbCr422    = 1,    ///< Color format.
    YcbCr444    = 2,    ///< Color format.
};

/// Specifies the private display information.
struct PrivateDisplayMode
{
    Extent2d                    sourceSize;       ///< Source image size.
    uint64                      pixelClockInKhz;  ///< Timing parameters - pixel clock in KHz with 10KHz resolution.
    PrivateDisplayTiming        horizontalTiming; ///< Horizontal timing.
    PrivateDisplayTiming        verticalTiming;   ///< Vertical timing.
    PrivateDisplayColorDepth    colorDepth;       ///< Indicate the color depth to be sent to display.
    PrivateDisplayPixelEncoding pixelEncoding;    ///< Indicate the pixel encoding, pixelEncoding and colorDepth define
                                                  ///  how pixel data is packed for sending to display.
    bool                        scalingEnabled;   ///< scalingEnabled, destinationSize and offset are display scaler
                                                  ///  controls. If scaling is disabled, the latter two don't have any
                                                  ///  effect.
    Extent2d                    destinationSize;  ///< The dimension of destination display.
    Offset2d                    offset;           ///< The offset of destination.

    union
    {
        struct
        {
            uint32 slsTiledLayout : 1;  ///< The tiled layout of VR SLS, if it's 1 means two displays will use the same
                                        ///  virtual timings. Otherwise, the two displays will use their own "physical"
                                        ///  timings.
            uint32 reserved       : 31; ///< Reserved bits
        };
        uint32 u32All;                  ///< Flags packed as 32-bit uint.
    } flags;
};

/// Specifies the power state of private display.
enum class PrivateDisplayPowerState : uint32
{
    PowerOn  = 1,   ///< Indicates power on to private display.
    PowerOff = 2,   ///< Indicates power off to private display.
};

/// Specifies the color transform matrix which is effectively 4x3 matrix multiply with the output color.
struct ColorTransform
{
    float matrix[12];   ///< matrix of color transform.
};

/// Specifies the HDCP status on private screen - whether it is active or not, and any error has occurred.
struct HdcpStatus
{
    bool active;    ///< True indicates HDCP is on, and also the following flags are valid.
    union
    {
        struct
        {
            uint32 linkLost                  : 1;   ///< HDCP link is lost.
            uint32 renegotiationRequired     : 1;   ///< HDCP requires renegotiation.
            uint32 tamperingDetected         : 1;   ///< Tampering is detected.
            uint32 revokedHdcpDeviceAttached : 1;   ///< A revoked HDCP device is attached.
            uint32 reserved                  :28;   ///< Reserved bits
        };
        uint32 u32All;  ///< Flags packed as 32-bit uint.
    } flags;    ///< HDCP status flags - only valid when active is true.
};

/**
 ***********************************************************************************************************************
 * @interface IPrivateScreen
 * @brief     Represents a private screen, which is a screen not exposed through standard OS mechanisms. The users can
 *            still enumerate, configure and present to private screens via private functions. This is initially to
 *            support VR headsets (HMDs).
 *
 ***********************************************************************************************************************
 */
class IPrivateScreen
{
public:
    /// Binds a pointer to the owner object when a IPrivateScreen object is destroyed. This is to protect the access to
    /// the IPrivateScreen object reference in owner object.
    ///
    /// @param [in] pOwner Pointer to an object that represents the owner of this private screen.
    virtual void BindOwner(void* pOwner) = 0;

    /// Reports properties of this screen (format, extent, refresh rate, etc.).
    ///
    /// @param [in,out] pNumFormats Pointer to number of formats. If null, the pFormats in pInfo is not filled, which
    ///                 also implies that pInfo must not be null. If both pInfo and pNumFormats are not null, the value
    ///                 of *pNumFormats must be large enough to copy into pFormats in pInfo.
    /// @param [in,out] pEdidSize Pointer to size of EDID in bytes. If null, the EDID in pInfo is not filled, which also
    ///                 implies that pInfo must not be null. If both pInfo and pEdidSize are not null, the value of
    ///                 *pEdidSize must not exceed size of edid array in pInfo.
    /// @param [out]    pInfo Output properties. If pInfo is null, pNumFormats and pEdidSize must not be null as the two
    ///                 are used to return data sizes needed.
    ///
    /// @returns Success if the properties were successfully queried. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorInvalidPointer if pNumFormats, pEdidSize, pInfo are all nullptr.
    ///          + ErrorInvalidMemorySize if the *pNumFormats or *pEdidSize is less than required
    ///          + ErrorPrivateScreenRemoved if the private screen was removed
    ///          + ErrorUnavalable if this operation isn't supported.
    virtual Result GetProperties(
        size_t*                  pNumFormats,
        size_t*                  pEdidSize,
        PrivateScreenProperties* pInfo) const = 0;

    /// Reports statistics of present on this screen (presentCount, presentCpuTime, etc.).
    ///
    /// @param [out] pStats Output statistics. Must not be null.
    ///
    /// @returns Success if the statistics were successfully queried. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenRemoved if the private screen was removed
    ///          + ErrorUnavalable if this operation isn't supported.
    virtual Result GetPresentStats(
        PrivateScreenPresentStats* pStats) = 0;

    /// Enables the private screen (provides exclusive ownership of the screen).
    ///
    /// @param [in] info Information used for enabling a private screen.
    ///
    /// @returns Success if the screen was successfully enabled. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenUsed if the private screen has already been enabled
    ///          + ErrorPrivateScreenRemoved if the private screen was removed
    ///          + ErrorUnavalable if this operation isn't supported.
    virtual Result Enable(
        const PrivateScreenEnableInfo& info) = 0;

    /// Disables the private screen (releases exclusive ownership of the screen).
    ///
    /// @returns Success if the screen was successfully disabled. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorInvalidFormat if the format specified is not supported by private screen.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed
    ///          + ErrorUnavalable if this operation isn't supported.
    virtual Result Disable() = 0;

    /// Blanks the private screen. This is for applicaiton to do some power management and screen saver features.
    /// This function calls into KMD/DAL to turn off visibility of this screen.
    ///
    /// @returns Success if the screen was successfully blanked. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    virtual Result Blank() = 0;

    /// Presents on the private screen. Presentation operations for private screens have "flip" semantics. The
    /// application is responsible for implementation of a swap chain from a required number of presentable images.
    /// The private screen must be enabled before presentation and the first present call lights up the screen before
    /// displaying an image.
    ///
    /// @param [in] presentInfo Presentation info.
    ///
    /// @returns Success if the present was successfully executed. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorInvalidPointer if presentInfo.pSrcImg is nullptr.
    ///          + ErrorInvalidImage if presentInfo.pSrcImg wasn't created on private screen.
    ///          + ErrorPrivateScreenInvalidFormat if the format isn't supported on the private screen.
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed
    ///          + ErrorUnavalable if this operation isn't supported.
    virtual Result Present(
        const PrivateScreenPresentInfo& presentInfo) = 0;

    /// Reports the line currently being scanned out by private screen, for coordination between the CPU and screen.
    ///
    /// @param [out] pScanLine Pointer to current scan line. A value of -1 indicates the screen is currently in its
    ///              vertical blanking period. Must not be null.
    ///
    /// @returns Success if the scan line is successfully reported. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorInvalidPointer if pScanLine is nullptr.
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result GetScanLine(
        int32* pScanLine) = 0;

    /// GetConnectorProperties should be call twice. In the first call, the size of buffer (pDataSize) will be reported
    /// which will be used by caller to allocate the buffer. In the second call, the caller pass in the buffer and
    /// retrieve the connector properties.
    ///
    /// @param [in,out] pDataSize The size of PrivateScreenConnectorProperties
    /// @param [out]    pConnectorProperties Output properties. If pConnectorProperties is null, pDataSize would
    ///                 pointer to the data size of PrivateScreenConnectorProperties.
    ///
    /// @returns Success if get connectorproperties via escape is successfully. Otherwise, one of the following errors
    ///          may be returned:
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result GetConnectorProperties(
        uint32*                           pDataSize,
        PrivateScreenConnectorProperties* pConnectorProperties) = 0;

    /// Reports the cached data of PrivateDisplayMode, it is set when calling PrivateScreen::Enable or
    /// PrivateScreen::SetDisplayMode.
    ///
    /// @param [out] pMode pointer to the PrivateDisplayMode
    ///
    /// @returns Success if the display mode is successfully reported. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result GetDisplayMode(
        PrivateDisplayMode* pMode) = 0;

    /// Sets gamma ramp for private display.
    ///
    /// @param [in] pGammaRamp Pointer to gamma ramp data, if it is null KMD would restore the gamma ramp to default.
    ///
    /// @returns Success if set gamma ramp via escape is successfully. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result SetGammaRamp(
        const GammaRamp* pGammaRamp) = 0;

    /// Sets private display power mode (turn power on or power off).
    ///
    /// @param [in] powerMode Indicate power on or power off
    ///
    /// @returns Success if set power mode via escape is successfully. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result SetPowerMode(
        PrivateDisplayPowerState powerMode) = 0;

    /// Sets and caches the private display mode.
    ///
    /// @param [in] displayMode Private display mode info.
    ///
    /// @returns Success (or OutOfSpec as a warning) if set display mode via escape is successfully. Otherwise, one of
    ///          the following errors may be returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorPrivateScreenInvalidTiming if the timing is invalid on the private screen.
    ///          + ErrorPrivateScreenInvalidScaling if the scaling is invalid on the private screen.
    ///          + ErrorPrivateScreenInvalidResolution if the resolution is valid on the private screen.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result SetDisplayMode(
        const PrivateDisplayMode& displayMode) = 0;

    /// Sets color transform matrix, the maxtrix (include scaling, bias) will multiply with the output color.
    ///
    /// @param [in] matrix Color transforms matrix data
    ///
    /// @returns Success if set color matrix via escape is successfully. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result SetColorMatrix(
        const ColorTransform& matrix) = 0;

    /// Sets an event to be signalled by KMD after a vsync occurs with a specified delay time in microseconds.
    ///
    /// The use is to get a regular beat relative to vsync to kick off present and other operations ahead of the next
    /// vsync without burning a CPU core and without need to have a previous present.
    ///
    /// @param [in] hEvent Event object to be signalled by KMD after a vsync occurs on this private screen.
    /// @param [in] delayInUs Delay in microseconds after a vsync occurs.
    /// @param [in] repeated True indicates this event would be signalled repeatedly.
    ///
    /// @returns Success if the event is set successfully. Otherwise, one of the following errors may be returned:
    ///
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result SetEventAfterVsync(
        OsExternalHandle hEvent,
        uint32           delayInUs,
        bool             repeated) = 0;

    /// Gets HDCP status on this private screen.
    ///
    /// @param [out] pStatus HDCP status @see HdcpStatus, indicating whether HDCP is on and any error occurs or not.
    ///
    /// @returns Success if HDCP status is retrieved successfully. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenNotEnabled if the private screen was not enabled.
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result GetHdcpStatus(
        HdcpStatus* pStatus) = 0;

    /// Controls HDMI audio on this private screen.
    ///
    /// @param [in] enable True to enable HDMI audio, false to disable it.
    ///
    /// @returns Success if audio is toggled successfully. Otherwise, one of the following errors may be
    ///          returned:
    ///          + ErrorPrivateScreenRemoved if the private screen was removed.
    ///          + ErrorUnavalable if this operation isn't supported.
    ///
    virtual Result EnableAudio(
        bool enable) = 0;

    /// Returns the value of the associated arbitrary client data pointer.
    /// Can be used to associate arbitrary data with a particular PAL object.
    ///
    /// @returns Pointer to client data.
    PAL_INLINE void* GetClientData() const
    {
        return m_pClientData;
    }

    /// Sets the value of the associated arbitrary client data pointer.
    /// Can be used to associate arbitrary data with a particular PAL object.
    ///
    /// @param  [in]    pClientData     A pointer to arbitrary client data.
    PAL_INLINE void SetClientData(
        void* pClientData)
    {
        m_pClientData = pClientData;
    }

protected:
    /// @internal Constructor. Prevent use of new operator on this interface. Client must create objects by explicitly
    /// called the proper create method.
    IPrivateScreen() : m_pClientData(nullptr) {}

    /// @internal Destructor.  Prevent use of delete operator on this interface.  Screens will be destroyed when the
    /// associated device is destroyed.
    virtual ~IPrivateScreen() { }

private:
    /// @internal Client data pointer. This can have an arbitrary value and can be returned by calling GetClientData()
    /// and set via SetClientData().
    /// For non-top-layer objects, this will point to the layer above the current object.
    void* m_pClientData;
};

} // Pal
