/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2018-2019 Advanced Micro Devices, Inc. All Rights Reserved.
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING!
//
// This code has been generated automatically. Do not hand-modify this code.
//
// When changes are needed, modify the tools generating this module in the tools\generate directory.
//
// WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING!  WARNING! WARNING!  WARNING!  WARNING!  WARNING!
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

/**
***********************************************************************************************************************
* @file  g_gfx9MergedDataFormats.h
* @brief Auto-generated file that describes the channel format properties for Gfx9.
***********************************************************************************************************************
*/

#include "pal.h"
#include "core/device.h"
#include "core/hw/gfxip/gfx9/gfx9FormatInfo.h"

namespace Pal
{
namespace Formats
{
namespace Gfx9
{

// Handy flag combinations that we can use to build the format support info table.
//
// Translation table:
//   B    = blending
//   C    = color target
//   D    = depth target
//   I    = image, used in conjunction with "r", "w", "a", "fl", and "fmm"
//   M    = multi-sampled
//   S    = stencil
//   T    = memory view in a shader, used in conjunction with "r", "w", and "a"
//   X    = format conversion
//   P    = windowed-mode present
//   r    = read
//   w    = write
//   a    = atomics
//   fl   = filter linear
constexpr FormatFeatureFlags None                     = static_cast<FormatFeatureFlags>(0);
constexpr FormatFeatureFlags Copy                     = static_cast<FormatFeatureFlags>(FormatFeatureCopy);
constexpr FormatFeatureFlags Xd                       = static_cast<FormatFeatureFlags>(FormatFeatureFormatConversionDst);
constexpr FormatFeatureFlags IrXs                     = static_cast<FormatFeatureFlags>(Copy                         |
                                                                                        FormatFeatureImageShaderRead |
                                                                                        FormatFeatureFormatConversionSrc);
constexpr FormatFeatureFlags Iw                       = static_cast<FormatFeatureFlags>(Copy | FormatFeatureImageShaderWrite);
constexpr FormatFeatureFlags IwXd                     = static_cast<FormatFeatureFlags>(Iw | Xd);
constexpr FormatFeatureFlags Ia                       = static_cast<FormatFeatureFlags>(FormatFeatureImageShaderAtomics);
constexpr FormatFeatureFlags Ifl                      = static_cast<FormatFeatureFlags>(FormatFeatureImageFilterLinear);
constexpr FormatFeatureFlags Ifmm                     = static_cast<FormatFeatureFlags>(FormatFeatureImageFilterMinMax);
constexpr FormatFeatureFlags Tr                       = static_cast<FormatFeatureFlags>(FormatFeatureMemoryShaderRead);
constexpr FormatFeatureFlags Tw                       = static_cast<FormatFeatureFlags>(FormatFeatureMemoryShaderWrite);
constexpr FormatFeatureFlags Ta                       = static_cast<FormatFeatureFlags>(FormatFeatureMemoryShaderAtomics);
constexpr FormatFeatureFlags CB                       = static_cast<FormatFeatureFlags>(Copy | FormatFeatureColorTargetWrite |
                                                                                        FormatFeatureColorTargetBlend);
constexpr FormatFeatureFlags CBP                      = static_cast<FormatFeatureFlags>(CB | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags CBX                      = static_cast<FormatFeatureFlags>(CB | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags CBXP                     = static_cast<FormatFeatureFlags>(CBX | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIfl                  = static_cast<FormatFeatureFlags>(IrXs | Ifl);
constexpr FormatFeatureFlags IrXsIflIfmm              = static_cast<FormatFeatureFlags>(IrXsIfl | Ifmm);
constexpr FormatFeatureFlags IrXsIw                   = static_cast<FormatFeatureFlags>(IrXs | Iw);
constexpr FormatFeatureFlags IrXsIwIfl                = static_cast<FormatFeatureFlags>(IrXs | Iw | Ifl);
constexpr FormatFeatureFlags IrXsIa                   = static_cast<FormatFeatureFlags>(IrXs | Ia);
constexpr FormatFeatureFlags IrXsIaIfl                = static_cast<FormatFeatureFlags>(IrXs | Ia | Ifl);
constexpr FormatFeatureFlags IrXsIaIflIfmm            = static_cast<FormatFeatureFlags>(IrXsIaIfl | Ifmm);
constexpr FormatFeatureFlags TrTw                     = static_cast<FormatFeatureFlags>(Tr | Tw);
constexpr FormatFeatureFlags TrTa                     = static_cast<FormatFeatureFlags>(Tr | Ta);
constexpr FormatFeatureFlags IrXsTr                   = static_cast<FormatFeatureFlags>(IrXs | Tr);
constexpr FormatFeatureFlags IrXsIflTr                = static_cast<FormatFeatureFlags>(IrXs | Ifl | Tr);
constexpr FormatFeatureFlags IrXsTrTw                 = static_cast<FormatFeatureFlags>(IrXs | TrTw);
constexpr FormatFeatureFlags IrXsIfmmTrTw             = static_cast<FormatFeatureFlags>(IrXsTrTw | Ifmm);
constexpr FormatFeatureFlags IrXsIflTrTa              = static_cast<FormatFeatureFlags>(IrXsIfl | TrTa);
constexpr FormatFeatureFlags IrXsIflTrTw              = static_cast<FormatFeatureFlags>(IrXsIfl | TrTw);
constexpr FormatFeatureFlags IrXsIflIfmmTrTw          = static_cast<FormatFeatureFlags>(IrXsIflTrTw | Ifmm);
constexpr FormatFeatureFlags IrXsIwTrTw               = static_cast<FormatFeatureFlags>(IrXsIw | TrTw);
constexpr FormatFeatureFlags IrXsIwIflTrTw            = static_cast<FormatFeatureFlags>(IrXsIwIfl | TrTw);
constexpr FormatFeatureFlags IrXsIaTrTa               = static_cast<FormatFeatureFlags>(IrXsIa | Tr | Ta);
constexpr FormatFeatureFlags IrXsIaIflTrTa            = static_cast<FormatFeatureFlags>(IrXsIaIfl | Tr | Ta);
constexpr FormatFeatureFlags IrXsIwIaTrTwTa           = static_cast<FormatFeatureFlags>(IrXsIaTrTa | Iw | Tw);
constexpr FormatFeatureFlags IrXsIwIaIfmmTrTwTa       = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTa | Ifmm);
constexpr FormatFeatureFlags IrXsIflTrTaM             = static_cast<FormatFeatureFlags>(IrXsIflTrTa | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwIaTrTwTaM          = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTa | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwIaIfmmTrTwTaM      = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTaM | Ifmm);
constexpr FormatFeatureFlags IrXsIwIaIflTrTwTa        = static_cast<FormatFeatureFlags>(IrXsIaIflTrTa | Iw | Tw);
constexpr FormatFeatureFlags IrXsIwIaTrTwTaP          = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTa | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwIaTrTwTaMP         = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTaP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwTrTwP              = static_cast<FormatFeatureFlags>(IrXsIwTrTw | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwTrTwM              = static_cast<FormatFeatureFlags>(IrXsIwTrTw | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwTrTwMP             = static_cast<FormatFeatureFlags>(IrXsIwTrTwP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsCB                   = static_cast<FormatFeatureFlags>(IrXs | CB);
constexpr FormatFeatureFlags IrXsIflCB                = static_cast<FormatFeatureFlags>(IrXsIfl | CB);
constexpr FormatFeatureFlags IrXsCBX                  = static_cast<FormatFeatureFlags>(IrXsCB | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIflCBX               = static_cast<FormatFeatureFlags>(IrXsIflCB | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsXdIflCBX             = static_cast<FormatFeatureFlags>(IrXsIflCBX | FormatFeatureFormatConversionDst);
constexpr FormatFeatureFlags IrXsXdIflIfmmCBX         = static_cast<FormatFeatureFlags>(IrXsXdIflCBX | Ifmm);
constexpr FormatFeatureFlags IrXsXdIflIfmmCBXP        = static_cast<FormatFeatureFlags>(IrXsXdIflIfmmCBX | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsXdIflIfmmTaCBXP      = static_cast<FormatFeatureFlags>(IrXsXdIflIfmmCBXP | Ta);
constexpr FormatFeatureFlags IrXsCBP                  = static_cast<FormatFeatureFlags>(IrXsCB | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsM                    = static_cast<FormatFeatureFlags>(IrXs | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIflM                 = static_cast<FormatFeatureFlags>(IrXsIfl | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsDM                   = static_cast<FormatFeatureFlags>(IrXsM | FormatFeatureDepthTarget);
constexpr FormatFeatureFlags IrXsTrM                  = static_cast<FormatFeatureFlags>(IrXsTr | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIflTrM               = static_cast<FormatFeatureFlags>(IrXsIflTr | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIaTrTaM              = static_cast<FormatFeatureFlags>(IrXsIaTrTa | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIaIflTrTaM           = static_cast<FormatFeatureFlags>(IrXsIaIflTrTa | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsSM                   = static_cast<FormatFeatureFlags>(IrXs | FormatFeatureStencilTarget |
                                                                                        FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsDSM                  = static_cast<FormatFeatureFlags>(IrXsDM | IrXsSM);
constexpr FormatFeatureFlags IrXsCBM                  = static_cast<FormatFeatureFlags>(IrXsCB | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIflCBM               = static_cast<FormatFeatureFlags>(IrXsIflCB | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsCBMX                 = static_cast<FormatFeatureFlags>(IrXsCBM | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIflCBMX              = static_cast<FormatFeatureFlags>(IrXsIflCBM | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsXdIflCBMX            = static_cast<FormatFeatureFlags>(IrXsIflCBMX | FormatFeatureFormatConversionDst);
constexpr FormatFeatureFlags IrXsXdIflIfmmCBMX        = static_cast<FormatFeatureFlags>(IrXsXdIflCBMX | Ifmm);
constexpr FormatFeatureFlags IrXsXdIflIfmmCBMXP       = static_cast<FormatFeatureFlags>(IrXsXdIflIfmmCBMX | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsXdIflIfmmTaCBMXP     = static_cast<FormatFeatureFlags>(IrXsXdIflIfmmCBMXP | Ta);
constexpr FormatFeatureFlags IrXsCBMP                 = static_cast<FormatFeatureFlags>(IrXsCBM | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIaTaCBP              = static_cast<FormatFeatureFlags>(IrXs | Ia | Ta | CBP);
constexpr FormatFeatureFlags IrXsIaIflTaCBP           = static_cast<FormatFeatureFlags>(IrXs | Ia | Ifl | Ta | CBP);
constexpr FormatFeatureFlags IrXsIaTaCBXP             = static_cast<FormatFeatureFlags>(IrXsIaTaCBP | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIaIflTaCBXP          = static_cast<FormatFeatureFlags>(IrXsIaIflTaCBP | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsXdIaIflTaCBXP        = static_cast<FormatFeatureFlags>(IrXsIaIflTaCBXP | FormatFeatureFormatConversionDst);
constexpr FormatFeatureFlags IrXsXdIaIflIfmmTaCBXP    = static_cast<FormatFeatureFlags>(IrXsXdIaIflTaCBXP | Ifmm);
constexpr FormatFeatureFlags IrXsIaTaCBMP             = static_cast<FormatFeatureFlags>(IrXsIaTaCBP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIaIflTaCBMP          = static_cast<FormatFeatureFlags>(IrXsIaIflTaCBP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIaTaCBMXP            = static_cast<FormatFeatureFlags>(IrXsIaTaCBMP | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIaIflTaCBMXP         = static_cast<FormatFeatureFlags>(IrXsIaIflTaCBMP | FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsXdIaIflTaCBMXP       = static_cast<FormatFeatureFlags>(IrXsIaIflTaCBMXP | FormatFeatureFormatConversionDst);
constexpr FormatFeatureFlags IrXsXdIaIflIfmmTaCBMXP   = static_cast<FormatFeatureFlags>(IrXsXdIaIflTaCBMXP | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdCBX              = static_cast<FormatFeatureFlags>(IrXsIw | CBX | Xd);
constexpr FormatFeatureFlags IrXsIwXdIflCBX           = static_cast<FormatFeatureFlags>(IrXsIwIfl | CBX | Xd);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmCBX       = static_cast<FormatFeatureFlags>(IrXsIwXdIflCBX | Ifmm);
constexpr FormatFeatureFlags IrXsIwIaTrTwTaBP         = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTa                  |
                                                                                        FormatFeatureColorTargetBlend |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwIaTrTwTaBMP        = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTaBP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCX       = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTa | Xd           |
                                                                                        FormatFeatureColorTargetWrite |
                                                                                        FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIwXdIaIfmmTrTwTaCX   = static_cast<FormatFeatureFlags>(IrXsIwXdIaTrTwTaCX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCMX      = static_cast<FormatFeatureFlags>(IrXsIwXdIaTrTwTaCX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIaIfmmTrTwTaCMX  = static_cast<FormatFeatureFlags>(IrXsIwXdIaTrTwTaCMX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCBX      = static_cast<FormatFeatureFlags>(IrXsIwIaTrTwTa | CBX | Xd);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCBX   = static_cast<FormatFeatureFlags>(IrXsIwIaIflTrTwTa | CBX | Xd);
constexpr FormatFeatureFlags IrXsIwXdIaIflIfmmTrTwTaCBX = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCBX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCBMX     = static_cast<FormatFeatureFlags>(IrXsIwXdIaTrTwTaCBX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCBMX  = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCBX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIaIflIfmmTrTwTaCBMX  = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCBMX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdCBXP             = static_cast<FormatFeatureFlags>(IrXsIwXdCBX | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIflCBXP          = static_cast<FormatFeatureFlags>(IrXsIwXdIflCBX | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmCBXP      = static_cast<FormatFeatureFlags>(IrXsIwXdIflCBXP | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdCBMX             = static_cast<FormatFeatureFlags>(IrXsIwXdCBX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIflCBMX          = static_cast<FormatFeatureFlags>(IrXsIwXdIflCBX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmCBMX      = static_cast<FormatFeatureFlags>(IrXsIwXdIflCBMX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdCBMXP            = static_cast<FormatFeatureFlags>(IrXsIwXdCBXP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIflCBMXP         = static_cast<FormatFeatureFlags>(IrXsIwXdIflCBXP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmCBMXP     = static_cast<FormatFeatureFlags>(IrXsIwXdIflCBMXP | Ifmm);
constexpr FormatFeatureFlags IrXsIwTrTwBP             = static_cast<FormatFeatureFlags>(IrXsIwTrTw | FormatFeatureColorTargetBlend |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwTrTwBMP            = static_cast<FormatFeatureFlags>(IrXsIwTrTwBP | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdTrTwCX           = static_cast<FormatFeatureFlags>(IrXsIwTrTw | Xd               |
                                                                                        FormatFeatureColorTargetWrite |
                                                                                        FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIwXdIfmmTrTwCX       = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdCX               = static_cast<FormatFeatureFlags>(IrXsIw | Xd | FormatFeatureColorTargetWrite |
                                                                                        FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIwXdIflTrTwCX        = static_cast<FormatFeatureFlags>(IrXsIwIflTrTw | Xd            |
                                                                                        FormatFeatureColorTargetWrite |
                                                                                        FormatFeatureFormatConversion);
constexpr FormatFeatureFlags IrXsIwXdTrTwCXP          = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCX | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIflTrTwCXP       = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCX | FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCXP      = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCXP | Ia | Ta);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCX    = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCX | Ia | Ta);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCMX   = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCXP   = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCXP | Ia | Ta);
constexpr FormatFeatureFlags IrXsIwXdTrTwCMX          = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIfmmTrTwCMX      = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCMX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdTrTwCSMX         = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCMX |
                                                                                        FormatFeatureStencilTarget);
constexpr FormatFeatureFlags IrXsIwXdIfmmTrTwCSMX     = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCSMX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIflTrTwCMX       = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCX | FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdTrTwCMXP         = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCMX |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIflTrTwCMXP      = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCMX |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCMXP     = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCMXP | Ia | Ta);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCMXP  = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCMXP | Ia | Ta);
constexpr FormatFeatureFlags IrXsIwXdTrTwCBX          = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCX |
                                                                                        FormatFeatureColorTargetBlend);
constexpr FormatFeatureFlags IrXsIwXdIflTrTwCBX       = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCX |
                                                                                        FormatFeatureColorTargetBlend);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwCBX   = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCBX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwTaCBX = static_cast<FormatFeatureFlags>(IrXsIwXdIflIfmmTrTwCBX | Ta);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwCBXP  = static_cast<FormatFeatureFlags>(IrXsIwXdIflIfmmTrTwCBX |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCBXP     = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCBX | Ia | Ta |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCBXP  = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCBX | Ia | Ta |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwTaCBXP = static_cast<FormatFeatureFlags>(IrXsIwXdIflIfmmTrTwTaCBX |
                                                                                         FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwTaCBMXP = static_cast<FormatFeatureFlags>(IrXsIwXdIflIfmmTrTwTaCBXP |
                                                                                         FormatFeatureMsaaTarget);
constexpr FormatFeatureFlags IrXsIwXdIaIflIfmmTrTwTaCBXP = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCBXP | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdTrTwCBMX         = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCMX |
                                                                                        FormatFeatureColorTargetBlend);
constexpr FormatFeatureFlags IrXsIwXdIflTrTwCBMX      = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCMX |
                                                                                        FormatFeatureColorTargetBlend);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwCBMX  = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCBMX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwCBMXP = static_cast<FormatFeatureFlags>(IrXsIwXdIflIfmmTrTwCBMX |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwTaCBMX = static_cast<FormatFeatureFlags>(IrXsIwXdIflIfmmTrTwCBMX | Ta);
constexpr FormatFeatureFlags IrXsIwXdIflTrTwCBDMX     = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCBMX |
                                                                                        FormatFeatureDepthTarget);
constexpr FormatFeatureFlags IrXsIwXdIflIfmmTrTwCBDMX = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCBDMX | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIaTrTwTaCBMXP    = static_cast<FormatFeatureFlags>(IrXsIwXdTrTwCBMX | Ia | Ta |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCBMXP = static_cast<FormatFeatureFlags>(IrXsIwXdIflTrTwCBMX | Ia | Ta |
                                                                                        FormatFeatureWindowedPresent);
constexpr FormatFeatureFlags IrXsIwXdIaIflIfmmTrTwTaCBMXP = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCBMXP | Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIaIflTrTwTaCBDMX = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCBMXP |
                                                                                        FormatFeatureDepthTarget);
constexpr FormatFeatureFlags IrXsIwXdIaIflIfmmCBX     = static_cast<FormatFeatureFlags>(IrXsIwXdCBX |
                                                                                        Ia |
                                                                                        Ifl |
                                                                                        Ifmm);
constexpr FormatFeatureFlags IrXsIwXdIaIflIfmmTrTwTaCBDMX = static_cast<FormatFeatureFlags>(IrXsIwXdIaIflTrTwTaCBDMX | Ifmm);

// Lookup table for GPU access capabilities for each format/tiling-type pairing in Gfx9.
constexpr MergedFormatPropertiesTable Gfx9MergedFormatPropertiesTable =
{
    {
        // Note: Feature capabilities are listed in (linear, optimal) order.
        { None,                           None                           }, // ChNumFormat::Undefined
        { None,                           None                           }, // ChNumFormat::X1_Unorm
        { None,                           None                           }, // ChNumFormat::X1_Uscaled
        { IrXsIflIfmm,                    IrXsIflIfmm                    }, // ChNumFormat::X4Y4_Unorm
        { IrXsIfl,                        IrXsIfl                        }, // ChNumFormat::X4Y4_Uscaled
        { IrXsIflIfmm,                    IrXsIflIfmm                    }, // ChNumFormat::L4A4_Unorm
        { IrXsIwXdIflIfmmCBXP,            IrXsIwXdIflIfmmCBMXP           }, // ChNumFormat::X4Y4Z4W4_Unorm
        { IrXsIfl,                        IrXsIflM                       }, // ChNumFormat::X4Y4Z4W4_Uscaled
        { IrXsIwXdIflIfmmCBXP,            IrXsIwXdIflIfmmCBMXP           }, // ChNumFormat::X5Y6Z5_Unorm
        { IrXsIfl,                        IrXsIflM                       }, // ChNumFormat::X5Y6Z5_Uscaled
        { IrXsIwXdIflIfmmCBXP,            IrXsIwXdIflIfmmCBMXP           }, // ChNumFormat::X5Y5Z5W1_Unorm
        { IrXsIfl,                        IrXsIflM                       }, // ChNumFormat::X5Y5Z5W1_Uscaled
        { IrXsIwXdIflIfmmCBX,             IrXsIwXdIflIfmmCBMX            }, // ChNumFormat::X1Y5Z5W5_Unorm
        { IrXsIfl,                        IrXsIflM                       }, // ChNumFormat::X1Y5Z5W5_Uscaled
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::X8_Unorm
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::X8_Snorm
        { IrXsIflTr,                      IrXsIflTrM                     }, // ChNumFormat::X8_Uscaled
        { IrXsIflTr,                      IrXsIflTrM                     }, // ChNumFormat::X8_Sscaled
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCSMX           }, // ChNumFormat::X8_Uint
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCMX            }, // ChNumFormat::X8_Sint
        { IrXsXdIflIfmmCBX,               IrXsXdIflIfmmCBMX              }, // ChNumFormat::X8_Srgb
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::A8_Unorm
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::L8_Unorm
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::P8_Uint
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::X8Y8_Unorm
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::X8Y8_Snorm
        { IrXsIflTr,                      IrXsIflTrM                     }, // ChNumFormat::X8Y8_Uscaled
        { IrXsIflTr,                      IrXsIflTrM                     }, // ChNumFormat::X8Y8_Sscaled
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCMX            }, // ChNumFormat::X8Y8_Uint
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCMX            }, // ChNumFormat::X8Y8_Sint
        { IrXsXdIflIfmmCBX,               IrXsXdIflIfmmCBMX              }, // ChNumFormat::X8Y8_Srgb
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::L8A8_Unorm
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::X8Y8Z8W8_Unorm
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::X8Y8Z8W8_Snorm
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X8Y8Z8W8_Uscaled
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X8Y8Z8W8_Sscaled
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X8Y8Z8W8_Uint
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X8Y8Z8W8_Sint
        { IrXsXdIflIfmmTaCBXP,            IrXsXdIflIfmmTaCBMXP           }, // ChNumFormat::X8Y8Z8W8_Srgb
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::U8V8_Snorm_L8W8_Unorm
        { IrXsIwXdIaIflIfmmTrTwTaCBX,     IrXsIwXdIaIflIfmmTrTwTaCBMX    }, // ChNumFormat::X10Y11Z11_Float
        { IrXsIwXdIaIflIfmmTrTwTaCBXP,    IrXsIwXdIaIflIfmmTrTwTaCBMXP   }, // ChNumFormat::X11Y11Z10_Float
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::X10Y10Z10W2_Unorm
        { IrXsIwXdIflIfmmTrTwTaCBX,       IrXsIwXdIflIfmmTrTwTaCBMX      }, // ChNumFormat::X10Y10Z10W2_Snorm
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X10Y10Z10W2_Uscaled
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X10Y10Z10W2_Sscaled
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X10Y10Z10W2_Uint
        { IrXsIwIaIfmmTrTwTa,             IrXsIwIaIfmmTrTwTaM            }, // ChNumFormat::X10Y10Z10W2_Sint
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::X10Y10Z10W2Bias_Unorm
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::U10V10W10_Snorm_A2_Unorm
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBDMX       }, // ChNumFormat::X16_Unorm
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::X16_Snorm
        { IrXsIflTr,                      IrXsIflTrM                     }, // ChNumFormat::X16_Uscaled
        { IrXsIflTr,                      IrXsIflTrM                     }, // ChNumFormat::X16_Sscaled
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCMX            }, // ChNumFormat::X16_Uint
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCMX            }, // ChNumFormat::X16_Sint
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::X16_Float
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::L16_Unorm
        { IrXsIwXdIflIfmmTrTwTaCBX,       IrXsIwXdIflIfmmTrTwTaCBMX      }, // ChNumFormat::X16Y16_Unorm
        { IrXsIwXdIflIfmmTrTwTaCBX,       IrXsIwXdIflIfmmTrTwTaCBMX      }, // ChNumFormat::X16Y16_Snorm
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X16Y16_Uscaled
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X16Y16_Sscaled
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X16Y16_Uint
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X16Y16_Sint
        { IrXsIwXdIaIflIfmmTrTwTaCBX,     IrXsIwXdIaIflIfmmTrTwTaCBMX    }, // ChNumFormat::X16Y16_Float
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::X16Y16Z16W16_Unorm
        { IrXsIwXdIflIfmmTrTwTaCBXP,      IrXsIwXdIflIfmmTrTwTaCBMXP     }, // ChNumFormat::X16Y16Z16W16_Snorm
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X16Y16Z16W16_Uscaled
        { IrXsIflTrTa,                    IrXsIflTrTaM                   }, // ChNumFormat::X16Y16Z16W16_Sscaled
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X16Y16Z16W16_Uint
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X16Y16Z16W16_Sint
        { IrXsIwXdIaIflIfmmTrTwTaCBXP,    IrXsIwXdIaIflIfmmTrTwTaCBMXP   }, // ChNumFormat::X16Y16Z16W16_Float
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X32_Uint
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X32_Sint
        { IrXsIwXdIaIflIfmmTrTwTaCBX,     IrXsIwXdIaIflIfmmTrTwTaCBDMX   }, // ChNumFormat::X32_Float
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X32Y32_Uint
        { IrXsIwXdIaIfmmTrTwTaCX,         IrXsIwXdIaIfmmTrTwTaCMX        }, // ChNumFormat::X32Y32_Sint
        { IrXsIwXdIaIflIfmmTrTwTaCBX,     IrXsIwXdIaIflIfmmTrTwTaCBMX    }, // ChNumFormat::X32Y32_Float
        { IrXsIfmmTrTw,                   None                           }, // ChNumFormat::X32Y32Z32_Uint
        { IrXsIfmmTrTw,                   None                           }, // ChNumFormat::X32Y32Z32_Sint
        { IrXsIflIfmmTrTw,                None                           }, // ChNumFormat::X32Y32Z32_Float
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCMX            }, // ChNumFormat::X32Y32Z32W32_Uint
        { IrXsIwXdIfmmTrTwCX,             IrXsIwXdIfmmTrTwCMX            }, // ChNumFormat::X32Y32Z32W32_Sint
        { IrXsIwXdIflIfmmTrTwCBX,         IrXsIwXdIflIfmmTrTwCBMX        }, // ChNumFormat::X32Y32Z32W32_Float
        { None,                           IrXsDSM                        }, // ChNumFormat::D16_Unorm_S8_Uint
        { None,                           IrXsDSM                        }, // ChNumFormat::D32_Float_S8_Uint
        { IrXsIaIflIfmm,                  IrXsIaIflIfmm                  }, // ChNumFormat::X9Y9Z9E5_Float
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc1_Unorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc1_Srgb
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc2_Unorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc2_Srgb
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc3_Unorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc3_Srgb
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc4_Unorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc4_Snorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc5_Unorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc5_Snorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc6_Ufloat
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc6_Sfloat
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc7_Unorm
        { Copy,                           IrXsIfl                        }, // ChNumFormat::Bc7_Srgb
        { None,                           None                           }, // ChNumFormat::Etc2X8Y8Z8_Unorm
        { None,                           None                           }, // ChNumFormat::Etc2X8Y8Z8_Srgb
        { None,                           None                           }, // ChNumFormat::Etc2X8Y8Z8W1_Unorm
        { None,                           None                           }, // ChNumFormat::Etc2X8Y8Z8W1_Srgb
        { None,                           None                           }, // ChNumFormat::Etc2X8Y8Z8W8_Unorm
        { None,                           None                           }, // ChNumFormat::Etc2X8Y8Z8W8_Srgb
        { None,                           None                           }, // ChNumFormat::Etc2X11_Unorm
        { None,                           None                           }, // ChNumFormat::Etc2X11_Snorm
        { None,                           None                           }, // ChNumFormat::Etc2X11Y11_Unorm
        { None,                           None                           }, // ChNumFormat::Etc2X11Y11_Snorm
        { None,                           None                           }, // ChNumFormat::AstcLdr4x4_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr4x4_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr5x4_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr5x4_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr5x5_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr5x5_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr6x5_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr6x5_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr6x6_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr6x6_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr8x5_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr8x5_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr8x6_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr8x6_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr8x8_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr8x8_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr10x5_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr10x5_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr10x6_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr10x6_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr10x8_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr10x8_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr10x10_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr10x10_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr12x10_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr12x10_Srgb
        { None,                           None                           }, // ChNumFormat::AstcLdr12x12_Unorm
        { None,                           None                           }, // ChNumFormat::AstcLdr12x12_Srgb
        { None,                           None                           }, // ChNumFormat::AstcHdr4x4_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr5x4_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr5x5_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr6x5_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr6x6_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr8x5_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr8x6_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr8x8_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr10x5_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr10x6_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr10x8_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr10x10_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr12x10_Float
        { None,                           None                           }, // ChNumFormat::AstcHdr12x12_Float
        { IrXsIflIfmm,                    IrXsIflIfmm                    }, // ChNumFormat::X8Y8_Z8Y8_Unorm
        { IrXsIfl,                        IrXsIfl                        }, // ChNumFormat::X8Y8_Z8Y8_Uscaled
        { IrXsIflIfmm,                    IrXsIflIfmm                    }, // ChNumFormat::Y8X8_Y8Z8_Unorm
        { IrXsIfl,                        IrXsIfl                        }, // ChNumFormat::Y8X8_Y8Z8_Uscaled
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::AYUV
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::UYVY
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::VYUY
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::YUY2
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::YVY2
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::YV12
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::NV11
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::NV12
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::NV21
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::P016
        { IrXsIwXdCX,                     IrXsIwXdCX                     }, // ChNumFormat::P010
    }
};

// Stores a ChannelFmtInfo struct for each available channel format for mapping PAL channel formats to the format values
// for various hardware blocks.
constexpr MergedFmtInfo Gfx9MergedChannelFmtInfoTbl[] =
{
    // ChNumFormat::Undefined
    {
        ChNumFormat::Undefined,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X1_Unorm
    {
        ChNumFormat::X1_Unorm,             // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X1_Uscaled
    {
        ChNumFormat::X1_Uscaled,           // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X4Y4_Unorm
    {
        ChNumFormat::X4Y4_Unorm,           // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_4_4,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X4Y4_Uscaled
    {
        ChNumFormat::X4Y4_Uscaled,         // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_4_4,               // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::L4A4_Unorm
    {
        ChNumFormat::L4A4_Unorm,           // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_4_4,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X4Y4Z4W4_Unorm
    {
        ChNumFormat::X4Y4Z4W4_Unorm,       // ChNumFormat
        COLOR_4_4_4_4,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_4_4_4_4,           // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X4Y4Z4W4_Uscaled
    {
        ChNumFormat::X4Y4Z4W4_Uscaled,     // ChNumFormat
        COLOR_4_4_4_4,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_4_4_4_4,           // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X5Y6Z5_Unorm
    {
        ChNumFormat::X5Y6Z5_Unorm,         // ChNumFormat
        COLOR_5_6_5,                       // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_5_6_5,             // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X5Y6Z5_Uscaled
    {
        ChNumFormat::X5Y6Z5_Uscaled,       // ChNumFormat
        COLOR_5_6_5,                       // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_5_6_5,             // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X5Y5Z5W1_Unorm
    {
        ChNumFormat::X5Y5Z5W1_Unorm,       // ChNumFormat
        COLOR_1_5_5_5,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_1_5_5_5,           // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X5Y5Z5W1_Uscaled
    {
        ChNumFormat::X5Y5Z5W1_Uscaled,     // ChNumFormat
        COLOR_1_5_5_5,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_1_5_5_5,           // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X1Y5Z5W5_Unorm
    {
        ChNumFormat::X1Y5Z5W5_Unorm,       // ChNumFormat
        COLOR_5_5_5_1,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_5_5_5_1,           // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X1Y5Z5W5_Uscaled
    {
        ChNumFormat::X1Y5Z5W5_Uscaled,     // ChNumFormat
        COLOR_5_5_5_1,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_5_5_5_1,           // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8_Unorm
    {
        ChNumFormat::X8_Unorm,             // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8_Snorm
    {
        ChNumFormat::X8_Snorm,             // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8_Uscaled
    {
        ChNumFormat::X8_Uscaled,           // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8_Sscaled
    {
        ChNumFormat::X8_Sscaled,           // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_SSCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_SSCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_SSCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8_Uint
    {
        ChNumFormat::X8_Uint,              // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_8,                         // StencilFormat
    },
    // ChNumFormat::X8_Sint
    {
        ChNumFormat::X8_Sint,              // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8_Srgb
    {
        ChNumFormat::X8_Srgb,              // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::A8_Unorm
    {
        ChNumFormat::A8_Unorm,             // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::L8_Unorm
    {
        ChNumFormat::L8_Unorm,             // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::P8_Uint
    {
        ChNumFormat::P8_Uint,              // ChNumFormat
        COLOR_8,                           // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_8,                 // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_8,                 // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Unorm
    {
        ChNumFormat::X8Y8_Unorm,           // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Snorm
    {
        ChNumFormat::X8Y8_Snorm,           // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Uscaled
    {
        ChNumFormat::X8Y8_Uscaled,         // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Sscaled
    {
        ChNumFormat::X8Y8_Sscaled,         // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_SSCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_SSCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_SSCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Uint
    {
        ChNumFormat::X8Y8_Uint,            // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Sint
    {
        ChNumFormat::X8Y8_Sint,            // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Srgb
    {
        ChNumFormat::X8Y8_Srgb,            // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::L8A8_Unorm
    {
        ChNumFormat::L8A8_Unorm,           // ChNumFormat
        COLOR_8_8,                         // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8_8,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8_8,               // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8Z8W8_Unorm
    {
        ChNumFormat::X8Y8Z8W8_Unorm,       // ChNumFormat
        COLOR_8_8_8_8,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8_8_8_8,           // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8_8_8_8,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8Z8W8_Snorm
    {
        ChNumFormat::X8Y8Z8W8_Snorm,       // ChNumFormat
        COLOR_8_8_8_8,                     // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_8_8_8_8,           // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_8_8_8_8,           // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8Z8W8_Uscaled
    {
        ChNumFormat::X8Y8Z8W8_Uscaled,     // ChNumFormat
        COLOR_8_8_8_8,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_8_8_8_8,           // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_8_8_8_8,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8Z8W8_Sscaled
    {
        ChNumFormat::X8Y8Z8W8_Sscaled,     // ChNumFormat
        COLOR_8_8_8_8,                     // CB Channel Format
        NUMBER_SSCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_8_8_8_8,           // Image Channel Format
        IMG_NUM_FORMAT_SSCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_8_8_8_8,           // Buffer Image Format
        BUF_NUM_FORMAT_SSCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8Z8W8_Uint
    {
        ChNumFormat::X8Y8Z8W8_Uint,        // ChNumFormat
        COLOR_8_8_8_8,                     // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_8_8_8_8,           // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_8_8_8_8,           // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8Z8W8_Sint
    {
        ChNumFormat::X8Y8Z8W8_Sint,        // ChNumFormat
        COLOR_8_8_8_8,                     // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_8_8_8_8,           // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_8_8_8_8,           // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8Z8W8_Srgb
    {
        ChNumFormat::X8Y8Z8W8_Srgb,        // ChNumFormat
        COLOR_8_8_8_8,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_8_8_8_8,           // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_8_8_8_8,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::U8V8_Snorm_L8W8_Unorm
    {
        ChNumFormat::U8V8_Snorm_L8W8_Unorm, // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y11Z11_Float
    {
        ChNumFormat::X10Y11Z11_Float,      // ChNumFormat
        COLOR_11_11_10,                    // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_11_11_10,          // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_11_11_10,          // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X11Y11Z10_Float
    {
        ChNumFormat::X11Y11Z10_Float,      // ChNumFormat
        COLOR_10_11_11,                    // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_10_11_11,          // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_10_11_11,          // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y10Z10W2_Unorm
    {
        ChNumFormat::X10Y10Z10W2_Unorm,    // ChNumFormat
        COLOR_2_10_10_10,                  // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_2_10_10_10,        // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_2_10_10_10,        // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y10Z10W2_Snorm
    {
        ChNumFormat::X10Y10Z10W2_Snorm,    // ChNumFormat
        COLOR_2_10_10_10,                  // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_2_10_10_10,        // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_2_10_10_10,        // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y10Z10W2_Uscaled
    {
        ChNumFormat::X10Y10Z10W2_Uscaled,  // ChNumFormat
        COLOR_2_10_10_10,                  // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_2_10_10_10,        // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_2_10_10_10,        // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y10Z10W2_Sscaled
    {
        ChNumFormat::X10Y10Z10W2_Sscaled,  // ChNumFormat
        COLOR_2_10_10_10,                  // CB Channel Format
        NUMBER_SSCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_2_10_10_10,        // Image Channel Format
        IMG_NUM_FORMAT_SSCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_2_10_10_10,        // Buffer Image Format
        BUF_NUM_FORMAT_SSCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y10Z10W2_Uint
    {
        ChNumFormat::X10Y10Z10W2_Uint,     // ChNumFormat
        COLOR_2_10_10_10,                  // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_2_10_10_10,        // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_2_10_10_10,        // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y10Z10W2_Sint
    {
        ChNumFormat::X10Y10Z10W2_Sint,     // ChNumFormat
        COLOR_2_10_10_10,                  // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_2_10_10_10,        // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_2_10_10_10,        // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X10Y10Z10W2Bias_Unorm
    {
        ChNumFormat::X10Y10Z10W2Bias_Unorm, // ChNumFormat
        COLOR_2_10_10_10,                  // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_2_10_10_10,        // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_2_10_10_10,        // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::U10V10W10_Snorm_A2_Unorm
    {
        ChNumFormat::U10V10W10_Snorm_A2_Unorm, // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16_Unorm
    {
        ChNumFormat::X16_Unorm,            // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_16,                              // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16_Snorm
    {
        ChNumFormat::X16_Snorm,            // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16_Uscaled
    {
        ChNumFormat::X16_Uscaled,          // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16_Sscaled
    {
        ChNumFormat::X16_Sscaled,          // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_SSCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_SSCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_SSCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16_Uint
    {
        ChNumFormat::X16_Uint,             // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16_Sint
    {
        ChNumFormat::X16_Sint,             // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16_Float
    {
        ChNumFormat::X16_Float,            // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::L16_Unorm
    {
        ChNumFormat::L16_Unorm,            // ChNumFormat
        COLOR_16,                          // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_16,                // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_16,                // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16_Unorm
    {
        ChNumFormat::X16Y16_Unorm,         // ChNumFormat
        COLOR_16_16,                       // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_16_16,             // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_16_16,             // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16_Snorm
    {
        ChNumFormat::X16Y16_Snorm,         // ChNumFormat
        COLOR_16_16,                       // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_16_16,             // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_16_16,             // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16_Uscaled
    {
        ChNumFormat::X16Y16_Uscaled,       // ChNumFormat
        COLOR_16_16,                       // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_16_16,             // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_16_16,             // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16_Sscaled
    {
        ChNumFormat::X16Y16_Sscaled,       // ChNumFormat
        COLOR_16_16,                       // CB Channel Format
        NUMBER_SSCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_16_16,             // Image Channel Format
        IMG_NUM_FORMAT_SSCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_16_16,             // Buffer Image Format
        BUF_NUM_FORMAT_SSCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16_Uint
    {
        ChNumFormat::X16Y16_Uint,          // ChNumFormat
        COLOR_16_16,                       // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_16_16,             // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_16_16,             // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16_Sint
    {
        ChNumFormat::X16Y16_Sint,          // ChNumFormat
        COLOR_16_16,                       // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_16_16,             // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_16_16,             // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16_Float
    {
        ChNumFormat::X16Y16_Float,         // ChNumFormat
        COLOR_16_16,                       // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_16_16,             // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_16_16,             // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16Z16W16_Unorm
    {
        ChNumFormat::X16Y16Z16W16_Unorm,   // ChNumFormat
        COLOR_16_16_16_16,                 // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_16_16_16_16,       // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_16_16_16_16,       // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16Z16W16_Snorm
    {
        ChNumFormat::X16Y16Z16W16_Snorm,   // ChNumFormat
        COLOR_16_16_16_16,                 // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_16_16_16_16,       // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_16_16_16_16,       // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16Z16W16_Uscaled
    {
        ChNumFormat::X16Y16Z16W16_Uscaled, // ChNumFormat
        COLOR_16_16_16_16,                 // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_16_16_16_16,       // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_16_16_16_16,       // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16Z16W16_Sscaled
    {
        ChNumFormat::X16Y16Z16W16_Sscaled, // ChNumFormat
        COLOR_16_16_16_16,                 // CB Channel Format
        NUMBER_SSCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_16_16_16_16,       // Image Channel Format
        IMG_NUM_FORMAT_SSCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_16_16_16_16,       // Buffer Image Format
        BUF_NUM_FORMAT_SSCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16Z16W16_Uint
    {
        ChNumFormat::X16Y16Z16W16_Uint,    // ChNumFormat
        COLOR_16_16_16_16,                 // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_16_16_16_16,       // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_16_16_16_16,       // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16Z16W16_Sint
    {
        ChNumFormat::X16Y16Z16W16_Sint,    // ChNumFormat
        COLOR_16_16_16_16,                 // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_16_16_16_16,       // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_16_16_16_16,       // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X16Y16Z16W16_Float
    {
        ChNumFormat::X16Y16Z16W16_Float,   // ChNumFormat
        COLOR_16_16_16_16,                 // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_16_16_16_16,       // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_16_16_16_16,       // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32_Uint
    {
        ChNumFormat::X32_Uint,             // ChNumFormat
        COLOR_32,                          // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32,                // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32,                // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32_Sint
    {
        ChNumFormat::X32_Sint,             // ChNumFormat
        COLOR_32,                          // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32,                // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32,                // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32_Float
    {
        ChNumFormat::X32_Float,            // ChNumFormat
        COLOR_32,                          // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_32,                // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_32,                // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_32_FLOAT,                        // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32_Uint
    {
        ChNumFormat::X32Y32_Uint,          // ChNumFormat
        COLOR_32_32,                       // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32_32,             // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32_32,             // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32_Sint
    {
        ChNumFormat::X32Y32_Sint,          // ChNumFormat
        COLOR_32_32,                       // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32_32,             // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32_32,             // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32_Float
    {
        ChNumFormat::X32Y32_Float,         // ChNumFormat
        COLOR_32_32,                       // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_32_32,             // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_32_32,             // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32Z32_Uint
    {
        ChNumFormat::X32Y32Z32_Uint,       // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32_32_32,          // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32_32_32,          // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32Z32_Sint
    {
        ChNumFormat::X32Y32Z32_Sint,       // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32_32_32,          // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32_32_32,          // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32Z32_Float
    {
        ChNumFormat::X32Y32Z32_Float,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_32_32_32,          // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_32_32_32,          // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32Z32W32_Uint
    {
        ChNumFormat::X32Y32Z32W32_Uint,    // ChNumFormat
        COLOR_32_32_32_32,                 // CB Channel Format
        NUMBER_UINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32_32_32_32,       // Image Channel Format
        IMG_NUM_FORMAT_UINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32_32_32_32,       // Buffer Image Format
        BUF_NUM_FORMAT_UINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32Z32W32_Sint
    {
        ChNumFormat::X32Y32Z32W32_Sint,    // ChNumFormat
        COLOR_32_32_32_32,                 // CB Channel Format
        NUMBER_SINT,                       // CB Numeric Format
        IMG_DATA_FORMAT_32_32_32_32,       // Image Channel Format
        IMG_NUM_FORMAT_SINT,               // Image Numeric Format
        BUF_DATA_FORMAT_32_32_32_32,       // Buffer Image Format
        BUF_NUM_FORMAT_SINT,               // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X32Y32Z32W32_Float
    {
        ChNumFormat::X32Y32Z32W32_Float,   // ChNumFormat
        COLOR_32_32_32_32,                 // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_32_32_32_32,       // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_32_32_32_32,       // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::D16_Unorm_S8_Uint
    {
        ChNumFormat::D16_Unorm_S8_Uint,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_16,                              // ZFormat
        STENCIL_8,                         // StencilFormat
    },
    // ChNumFormat::D32_Float_S8_Uint
    {
        ChNumFormat::D32_Float_S8_Uint,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_32_FLOAT,                        // ZFormat
        STENCIL_8,                         // StencilFormat
    },
    // ChNumFormat::X9Y9Z9E5_Float
    {
        ChNumFormat::X9Y9Z9E5_Float,       // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_5_9_9_9,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc1_Unorm
    {
        ChNumFormat::Bc1_Unorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC1,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc1_Srgb
    {
        ChNumFormat::Bc1_Srgb,             // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_BC1,               // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc2_Unorm
    {
        ChNumFormat::Bc2_Unorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC2,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc2_Srgb
    {
        ChNumFormat::Bc2_Srgb,             // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_BC2,               // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc3_Unorm
    {
        ChNumFormat::Bc3_Unorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC3,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc3_Srgb
    {
        ChNumFormat::Bc3_Srgb,             // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_BC3,               // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc4_Unorm
    {
        ChNumFormat::Bc4_Unorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC4,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc4_Snorm
    {
        ChNumFormat::Bc4_Snorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC4,               // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc5_Unorm
    {
        ChNumFormat::Bc5_Unorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC5,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc5_Snorm
    {
        ChNumFormat::Bc5_Snorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC5,               // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc6_Ufloat
    {
        ChNumFormat::Bc6_Ufloat,           // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC6,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc6_Sfloat
    {
        ChNumFormat::Bc6_Sfloat,           // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC6,               // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc7_Unorm
    {
        ChNumFormat::Bc7_Unorm,            // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BC7,               // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Bc7_Srgb
    {
        ChNumFormat::Bc7_Srgb,             // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_BC7,               // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X8Y8Z8_Unorm
    {
        ChNumFormat::Etc2X8Y8Z8_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RGB__GFX09,   // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X8Y8Z8_Srgb
    {
        ChNumFormat::Etc2X8Y8Z8_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RGB__GFX09,   // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X8Y8Z8W1_Unorm
    {
        ChNumFormat::Etc2X8Y8Z8W1_Unorm,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RGBA1__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X8Y8Z8W1_Srgb
    {
        ChNumFormat::Etc2X8Y8Z8W1_Srgb,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RGBA1__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X8Y8Z8W8_Unorm
    {
        ChNumFormat::Etc2X8Y8Z8W8_Unorm,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RGBA__GFX09,  // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X8Y8Z8W8_Srgb
    {
        ChNumFormat::Etc2X8Y8Z8W8_Srgb,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SRGB,                       // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RGBA__GFX09,  // Image Channel Format
        IMG_NUM_FORMAT_SRGB,               // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X11_Unorm
    {
        ChNumFormat::Etc2X11_Unorm,        // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_R__GFX09,     // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X11_Snorm
    {
        ChNumFormat::Etc2X11_Snorm,        // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_R__GFX09,     // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X11Y11_Unorm
    {
        ChNumFormat::Etc2X11Y11_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RG__GFX09,    // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Etc2X11Y11_Snorm
    {
        ChNumFormat::Etc2X11Y11_Snorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_SNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_ETC2_RG__GFX09,    // Image Channel Format
        IMG_NUM_FORMAT_SNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_SNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr4x4_Unorm
    {
        ChNumFormat::AstcLdr4x4_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr4x4_Srgb
    {
        ChNumFormat::AstcLdr4x4_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr5x4_Unorm
    {
        ChNumFormat::AstcLdr5x4_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr5x4_Srgb
    {
        ChNumFormat::AstcLdr5x4_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr5x5_Unorm
    {
        ChNumFormat::AstcLdr5x5_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr5x5_Srgb
    {
        ChNumFormat::AstcLdr5x5_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr6x5_Unorm
    {
        ChNumFormat::AstcLdr6x5_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr6x5_Srgb
    {
        ChNumFormat::AstcLdr6x5_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr6x6_Unorm
    {
        ChNumFormat::AstcLdr6x6_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr6x6_Srgb
    {
        ChNumFormat::AstcLdr6x6_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr8x5_Unorm
    {
        ChNumFormat::AstcLdr8x5_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr8x5_Srgb
    {
        ChNumFormat::AstcLdr8x5_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr8x6_Unorm
    {
        ChNumFormat::AstcLdr8x6_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr8x6_Srgb
    {
        ChNumFormat::AstcLdr8x6_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr8x8_Unorm
    {
        ChNumFormat::AstcLdr8x8_Unorm,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr8x8_Srgb
    {
        ChNumFormat::AstcLdr8x8_Srgb,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x5_Unorm
    {
        ChNumFormat::AstcLdr10x5_Unorm,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x5_Srgb
    {
        ChNumFormat::AstcLdr10x5_Srgb,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x6_Unorm
    {
        ChNumFormat::AstcLdr10x6_Unorm,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x6_Srgb
    {
        ChNumFormat::AstcLdr10x6_Srgb,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x8_Unorm
    {
        ChNumFormat::AstcLdr10x8_Unorm,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x8_Srgb
    {
        ChNumFormat::AstcLdr10x8_Srgb,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x10_Unorm
    {
        ChNumFormat::AstcLdr10x10_Unorm,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr10x10_Srgb
    {
        ChNumFormat::AstcLdr10x10_Srgb,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr12x10_Unorm
    {
        ChNumFormat::AstcLdr12x10_Unorm,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr12x10_Srgb
    {
        ChNumFormat::AstcLdr12x10_Srgb,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr12x12_Unorm
    {
        ChNumFormat::AstcLdr12x12_Unorm,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcLdr12x12_Srgb
    {
        ChNumFormat::AstcLdr12x12_Srgb,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr4x4_Float
    {
        ChNumFormat::AstcHdr4x4_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr5x4_Float
    {
        ChNumFormat::AstcHdr5x4_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr5x5_Float
    {
        ChNumFormat::AstcHdr5x5_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr6x5_Float
    {
        ChNumFormat::AstcHdr6x5_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr6x6_Float
    {
        ChNumFormat::AstcHdr6x6_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr8x5_Float
    {
        ChNumFormat::AstcHdr8x5_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr8x6_Float
    {
        ChNumFormat::AstcHdr8x6_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr8x8_Float
    {
        ChNumFormat::AstcHdr8x8_Float,     // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr10x5_Float
    {
        ChNumFormat::AstcHdr10x5_Float,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr10x6_Float
    {
        ChNumFormat::AstcHdr10x6_Float,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr10x8_Float
    {
        ChNumFormat::AstcHdr10x8_Float,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr10x10_Float
    {
        ChNumFormat::AstcHdr10x10_Float,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr12x10_Float
    {
        ChNumFormat::AstcHdr12x10_Float,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AstcHdr12x12_Float
    {
        ChNumFormat::AstcHdr12x12_Float,   // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09, // Image Channel Format
        IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09, // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Z8Y8_Unorm
    {
        ChNumFormat::X8Y8_Z8Y8_Unorm,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_GB_GR,             // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::X8Y8_Z8Y8_Uscaled
    {
        ChNumFormat::X8Y8_Z8Y8_Uscaled,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_GB_GR,             // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Y8X8_Y8Z8_Unorm
    {
        ChNumFormat::Y8X8_Y8Z8_Unorm,      // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_UNORM,                      // CB Numeric Format
        IMG_DATA_FORMAT_BG_RG,             // Image Channel Format
        IMG_NUM_FORMAT_UNORM,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_UNORM,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::Y8X8_Y8Z8_Uscaled
    {
        ChNumFormat::Y8X8_Y8Z8_Uscaled,    // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_USCALED,                    // CB Numeric Format
        IMG_DATA_FORMAT_BG_RG,             // Image Channel Format
        IMG_NUM_FORMAT_USCALED,            // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_USCALED,            // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::AYUV
    {
        ChNumFormat::AYUV,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::UYVY
    {
        ChNumFormat::UYVY,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::VYUY
    {
        ChNumFormat::VYUY,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::YUY2
    {
        ChNumFormat::YUY2,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::YVY2
    {
        ChNumFormat::YVY2,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::YV12
    {
        ChNumFormat::YV12,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::NV11
    {
        ChNumFormat::NV11,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::NV12
    {
        ChNumFormat::NV12,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::NV21
    {
        ChNumFormat::NV21,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::P016
    {
        ChNumFormat::P016,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
    // ChNumFormat::P010
    {
        ChNumFormat::P010,                 // ChNumFormat
        COLOR_INVALID,                     // CB Channel Format
        NUMBER_FLOAT,                      // CB Numeric Format
        IMG_DATA_FORMAT_INVALID,           // Image Channel Format
        IMG_NUM_FORMAT_FLOAT,              // Image Numeric Format
        BUF_DATA_FORMAT_INVALID,           // Buffer Image Format
        BUF_NUM_FORMAT_FLOAT,              // Buffer Numeric Format
        Z_INVALID,                         // ZFormat
        STENCIL_INVALID,                   // StencilFormat
    },
};

// Stores a MergedImgDataFmtInfo struct for each HW image format up to the last format known to the spreadsheet.
constexpr MergedImgDataFmtInfo Gfx9MergedImgDataFmtTbl[] =
{
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_8,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X8_Unorm,
               ChNumFormat::A8_Unorm,
               ChNumFormat::L8_Unorm,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::X8_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::X8_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X8_Uint,
               ChNumFormat::P8_Uint,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X8_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::X8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_16,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X16_Unorm,
               ChNumFormat::L16_Unorm,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::X16_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X16_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::X16_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X16_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X16_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X16_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_8_8,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X8Y8_Unorm,
               ChNumFormat::L8A8_Unorm,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::X8Y8_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X8Y8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::X8Y8_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X8Y8_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X8Y8_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::X8Y8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_32,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_16_16,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X16Y16_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::X16Y16_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X16Y16_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::X16Y16_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X16Y16_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X16Y16_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X16Y16_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_10_11_11,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X11Y11Z10_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_11_11_10,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X10Y11Z11_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_2_10_10_10,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X10Y10Z10W2_Unorm,
               ChNumFormat::X10Y10Z10W2Bias_Unorm,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::X10Y10Z10W2_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X10Y10Z10W2_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::X10Y10Z10W2_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X10Y10Z10W2_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X10Y10Z10W2_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_8_8_8_8,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X8Y8Z8W8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::X8Y8Z8W8_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X8Y8Z8W8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::X8Y8Z8W8_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X8Y8Z8W8_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X8Y8Z8W8_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::X8Y8Z8W8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_32_32,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X32Y32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X32Y32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X32Y32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_16_16_16_16,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X16Y16Z16W16_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::X16Y16Z16W16_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X16Y16Z16W16_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::X16Y16Z16W16_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X16Y16Z16W16_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X16Y16Z16W16_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X16Y16Z16W16_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_32_32_32,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X32Y32Z32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X32Y32Z32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X32Y32Z32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_32_32_32_32,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::X32Y32Z32W32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::X32Y32Z32W32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X32Y32Z32W32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_5_6_5,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X5Y6Z5_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X5Y6Z5_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_1_5_5_5,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X5Y5Z5W1_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X5Y5Z5W1_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_5_5_5_1,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X1Y5Z5W5_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X1Y5Z5W5_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_4_4_4_4,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X4Y4Z4W4_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X4Y4Z4W4_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ETC2_RGB__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Etc2X8Y8Z8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Etc2X8Y8Z8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ETC2_RGBA__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Etc2X8Y8Z8W8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Etc2X8Y8Z8W8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ETC2_R__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Etc2X11_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Etc2X11_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ETC2_RG__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Etc2X11Y11_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Etc2X11Y11_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ETC2_RGBA1__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Etc2X8Y8Z8W1_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Etc2X8Y8Z8W1_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_GB_GR,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X8Y8_Z8Y8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X8Y8_Z8Y8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BG_RG,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Y8X8_Y8Z8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Y8X8_Y8Z8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_5_9_9_9,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::X9Y9Z9E5_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BC1,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Bc1_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Bc1_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BC2,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Bc2_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Bc2_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BC3,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Bc3_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Bc3_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BC4,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Bc4_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Bc4_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BC5,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Bc5_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Bc5_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BC6,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Bc6_Ufloat,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Bc6_Sfloat,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_BC7,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Bc7_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Bc7_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ASTC_2D_LDR__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::AstcLdr4x4_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::AstcLdr5x4_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::AstcLdr5x5_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::AstcLdr6x5_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::AstcLdr6x6_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::AstcLdr8x5_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::AstcLdr8x6_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::AstcLdr8x8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::AstcLdr10x5_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::AstcLdr10x6_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::AstcLdr10x8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::AstcLdr10x10_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::AstcLdr12x10_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::AstcLdr12x12_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ASTC_2D_HDR__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::AstcHdr4x4_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::AstcHdr5x4_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::AstcHdr5x5_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::AstcHdr6x5_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::AstcHdr6x6_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::AstcHdr8x5_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::AstcHdr8x6_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::AstcHdr8x8_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::AstcHdr10x5_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::AstcHdr10x6_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::AstcHdr10x8_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::AstcHdr10x10_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::AstcHdr12x10_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::AstcHdr12x12_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_ASTC_2D_LDR_SRGB__GFX09,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::AstcLdr4x4_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::AstcLdr5x4_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::AstcLdr5x5_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::AstcLdr6x5_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::AstcLdr6x6_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::AstcLdr8x5_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::AstcLdr8x6_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::AstcLdr8x8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::AstcLdr10x5_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::AstcLdr10x6_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::AstcLdr10x8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::AstcLdr10x10_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::AstcLdr12x10_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::AstcLdr12x12_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_INVALID,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { IMG_DATA_FORMAT_4_4,
      {
          { // IMG_NUM_FORMAT_UNORM / IMG_NUM_FORMAT_ASTC_2D_4x4__GFX09
               ChNumFormat::X4Y4_Unorm,
               ChNumFormat::L4A4_Unorm,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SNORM / IMG_NUM_FORMAT_ASTC_2D_5x4__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_USCALED / IMG_NUM_FORMAT_ASTC_2D_5x5__GFX09
               ChNumFormat::X4Y4_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SSCALED / IMG_NUM_FORMAT_ASTC_2D_6x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_UINT / IMG_NUM_FORMAT_ASTC_2D_6x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SINT / IMG_NUM_FORMAT_ASTC_2D_8x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_8x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_FLOAT / IMG_NUM_FORMAT_ASTC_2D_8x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x5__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_SRGB / IMG_NUM_FORMAT_ASTC_2D_10x6__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x8__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_10x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x10__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // IMG_NUM_FORMAT_ASTC_2D_12x12__GFX09
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
};

constexpr uint32 Gfx9MergedImgDataFmtCount = sizeof(Gfx9MergedImgDataFmtTbl) / sizeof(MergedImgDataFmtInfo);

// Stores a MergedBufDataFmtInfo struct for each HW buffer format up to the last format known to the spreadsheet.
constexpr MergedBufDataFmtInfo Gfx9MergedBufDataFmtTbl[] =
{
    { BUF_DATA_FORMAT_INVALID,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_8,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::X8_Unorm,
               ChNumFormat::A8_Unorm,
               ChNumFormat::L8_Unorm,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::X8_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::X8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::X8_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X8_Uint,
               ChNumFormat::P8_Uint,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X8_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_16,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::X16_Unorm,
               ChNumFormat::L16_Unorm,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::X16_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::X16_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::X16_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X16_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X16_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X16_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_8_8,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::X8Y8_Unorm,
               ChNumFormat::L8A8_Unorm,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::X8Y8_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::X8Y8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::X8Y8_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X8Y8_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X8Y8_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X8Y8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_32,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_16_16,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::X16Y16_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::X16Y16_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::X16Y16_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::X16Y16_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X16Y16_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X16Y16_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X16Y16_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_10_11_11,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X11Y11Z10_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_11_11_10,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X10Y11Z11_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_INVALID,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_2_10_10_10,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::X10Y10Z10W2_Unorm,
               ChNumFormat::X10Y10Z10W2Bias_Unorm,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::X10Y10Z10W2_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::X10Y10Z10W2_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::X10Y10Z10W2_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X10Y10Z10W2_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X10Y10Z10W2_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_8_8_8_8,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::X8Y8Z8W8_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::X8Y8Z8W8_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::X8Y8Z8W8_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::X8Y8Z8W8_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X8Y8Z8W8_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X8Y8Z8W8_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X8Y8Z8W8_Srgb,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_32_32,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X32Y32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X32Y32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X32Y32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_16_16_16_16,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::X16Y16Z16W16_Unorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::X16Y16Z16W16_Snorm,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::X16Y16Z16W16_Uscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::X16Y16Z16W16_Sscaled,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X16Y16Z16W16_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X16Y16Z16W16_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X16Y16Z16W16_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_32_32_32,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X32Y32Z32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X32Y32Z32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X32Y32Z32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
    { BUF_DATA_FORMAT_32_32_32_32,
      {
          { // BUF_NUM_FORMAT_UNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SNORM
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_USCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SSCALED
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_UINT
               ChNumFormat::X32Y32Z32W32_Uint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_SINT
               ChNumFormat::X32Y32Z32W32_Sint,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // Unused
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
          { // BUF_NUM_FORMAT_FLOAT
               ChNumFormat::X32Y32Z32W32_Float,
               ChNumFormat::Undefined,
               ChNumFormat::Undefined,
          },
      },
    },
};

constexpr uint32 Gfx9MergedBufDataFmtCount = sizeof(Gfx9MergedBufDataFmtTbl) / sizeof(MergedBufDataFmtInfo);

} // Gfx9
} // Formats
} // Pal
