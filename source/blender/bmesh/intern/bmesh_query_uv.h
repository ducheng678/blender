/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/** \file
 * \ingroup bmesh
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Retrieve the custom data offsets for layers used for user interaction with a UV map, returns the
 * active uv map if layer is -1.
 */
BMUVOffsets BM_uv_map_get_offsets(const BMesh *bm);
BMUVOffsets BM_uv_map_get_offsets_n(const BMesh *bm, int layer);

float BM_loop_uv_calc_edge_length_squared(const BMLoop *l,
                                          int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();
float BM_loop_uv_calc_edge_length(const BMLoop *l, int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

/**
 * Computes the UV center of a face, using the mean average weighted by edge length.
 *
 * See #BM_face_calc_center_median_weighted for matching spatial functionality.
 *
 * \param aspect: Calculate the center scaling by these values, and finally dividing.
 * Since correct weighting depends on having the correct aspect.
 */
void BM_face_uv_calc_center_median_weighted(const BMFace *f,
                                            const float aspect[2],
                                            int cd_loop_uv_offset,
                                            float r_cent[2]) ATTR_NONNULL();
void BM_face_uv_calc_center_median(const BMFace *f, int cd_loop_uv_offset, float r_cent[2])
    ATTR_NONNULL();

/**
 * Calculate the UV cross product (use the sign to check the winding).
 */
float BM_face_uv_calc_cross(const BMFace *f, int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

void BM_face_uv_minmax(const BMFace *f, float min[2], float max[2], int cd_loop_uv_offset);

bool BM_loop_uv_share_edge_check_with_limit(BMLoop *l_a,
                                            BMLoop *l_b,
                                            const float limit[2],
                                            int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT
    ATTR_NONNULL();

/**
 * Check if two loops that share an edge also have the same UV coordinates.
 */
bool BM_loop_uv_share_edge_check(BMLoop *l_a,
                                 BMLoop *l_b,
                                 int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

/**
 * Check if two loops that share a vertex also have the same UV coordinates.
 */
bool BM_edge_uv_share_vert_check(BMEdge *e, BMLoop *l_a, BMLoop *l_b, int cd_loop_uv_offset)
    ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

/**
 * Check if two loops that share a vertex also have the same UV coordinates.
 */
bool BM_loop_uv_share_vert_check(BMLoop *l_a,
                                 BMLoop *l_b,
                                 int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

/**
 * Check if the point is inside the UV face.
 */
bool BM_face_uv_point_inside_test(const BMFace *f,
                                  const float co[2],
                                  int cd_loop_uv_offset) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL();

#ifdef __cplusplus
}
#endif
