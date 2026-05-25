/**********************************************************************************
 * Copyright (c) 2024-2026 Wissem Chiha <chihawissem08@gmail.com>                 *
 * SPDX-License-Identifier: MIT                                                   *
 *                                                                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          *
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 *  The above copyright notice and this permission notice shall be included in all*
 *  copies or substantial portions of the Software.                               *
 *                                                                                *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    *
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,      *
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE   *
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER        *
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, *
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE *
 *  SOFTWARE.                                                                     *
 **********************************************************************************/
#ifndef URDF_H
#define URDF_H

#include "urdf/common/geometry_base.h"
#include "urdf/common/object_base.h"
#include "urdf/common/parser_base.h"
#include "urdf/common/property_base.h"
#include "urdf/common/property_parser.h"
#include "urdf/common/sensor_base.h"
#include "urdf/core/box.h"
#include "urdf/core/camera.h"
#include "urdf/core/collision.h"
#include "urdf/core/color.h"
#include "urdf/core/cylinder.h"
#include "urdf/core/image.h"
#include "urdf/core/inertia.h"
#include "urdf/core/joint.h"
#include "urdf/core/joint_calibration.h"
#include "urdf/core/joint_dynamics.h"
#include "urdf/core/joint_limits.h"
#include "urdf/core/joint_mimic.h"
#include "urdf/core/joint_safety.h"
#include "urdf/core/link.h"
#include "urdf/core/material.h"
#include "urdf/core/mesh.h"
#include "urdf/core/model.h"
#include "urdf/core/pose.h"
#include "urdf/core/sphere.h"
#include "urdf/core/visual.h"
#include "urdf/core/transmission.h"
#include "urdf/detail/internal_graph.h"
#include "urdf/internal/camera_parser.h"
#include "urdf/internal/color_parser.h"
#include "urdf/internal/geometry_parser.h"
#include "urdf/internal/inertia_parser.h"
#include "urdf/internal/joint_parser.h"
#include "urdf/internal/link_parser.h"
#include "urdf/internal/material_parser.h"
#include "urdf/internal/model_parser.h"
#include "urdf/internal/pose_parser.h"
#include "urdf/internal/version.h"
#include "urdf/utility/math_utils.h"
#include "urdf/internal/urdf_parser.h"
#include "urdf/utility/string_utils.h"

#endif // URDF_H