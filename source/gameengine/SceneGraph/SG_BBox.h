/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file SG_BBox.h
 *  \ingroup bgesg
 *  \brief Bounding Box
 */

#ifndef __SG_BBOX_H__
#define __SG_BBOX_H__

#include "MT_Vector3.h"

/**
 * Bounding box class.
 * Holds the minimum and maximum axis aligned points of a node's bounding box,
 * in world coordinates.
 */
class SG_BBox {
 private:
  /// AABB data.
  MT_Vector3 m_min;
  MT_Vector3 m_max;

  /// Sphere data.
  MT_Vector3 m_center;
  float m_radius;

  /// Update sphere data with current AABB data.
  void UpdateSphere();

 public:
  SG_BBox();
  SG_BBox(const MT_Vector3 &min, const MT_Vector3 &max);
  ~SG_BBox() = default;

  const MT_Vector3 &GetCenter() const;
  const float GetRadius() const;

  const MT_Vector3 &GetMin() const;
  const MT_Vector3 &GetMax() const;

  void Get(MT_Vector3 &min, MT_Vector3 &max) const;

  void SetMin(const MT_Vector3 &min);
  void SetMax(const MT_Vector3 &max);

  void Set(const MT_Vector3 &min, const MT_Vector3 &max);

  /// Test if the given point is inside this bounding box.
  bool Inside(const MT_Vector3 &point) const;
};

#endif  // __SG_BBOX_H__
