#pragma once

#include <CesiumGeospatial/Cartographic.h>

#include <string>
#include <vector>

// WS_BEGIN_CHANGE, WS_EXPOSE_HIT_FACE_NORMAL, 20/30
#include <optional>
#include <glm/ext/vector_double3.hpp>
// WS_END_CHANGE, WS_EXPOSE_HIT_FACE_NORMAL, 20/30

namespace Cesium3DTilesSelection {

/**
 * @brief The result of sampling heights with
 * @ref Tileset::sampleHeightMostDetailed.
 */
struct SampleHeightResult {
  /**
   * @brief The positions and their sampled heights.
   *
   * For each resulting position, its longitude and latitude values will match
   * values from its input. Its height will either be the height sampled from
   * the tileset at that position, or the original input height if the sample
   * was unsuccessful. To determine which, look at the value of
   * @ref SampleHeightResult::sampleSuccess at the same index.
   */
  std::vector<CesiumGeospatial::Cartographic> positions;

  // WS_BEGIN_CHANGE, WS_EXPOSE_HIT_FACE_NORMAL, 21/30
  /**
   * @brief The normals at the sampled positions.
   * 
   * For each resulting normal, it will be the normal vector sampled from the 
   * tileset at that position, or std::nullopt if the normal could not be sampled 
   * (e.g. due to a failed height sample or because the tile's content doesn't provide normals). 
   * To determine whether a normal was successfully sampled, look at the value of {@link SampleHeightResult::sampleSuccess} 
   * at the same index.
   * 
   */
  std::vector<std::optional<glm::dvec3>> normals;
  // WS_END_CHANGE, WS_EXPOSE_HIT_FACE_NORMAL, 21/30

  /**
   * @brief The success of each sample.
   *
   * Each entry specifies whether the height for the position at the
   * corresponding index was successfully sampled. If true, then
   * @ref SampleHeightResult::positions has a valid height sampled from the
   * tileset at this index. If false, the height could not be sampled, leaving
   * the height in @ref SampleHeightResult::positions unchanged from the
   * original input height.
   */
  std::vector<bool> sampleSuccess;

  /**
   * @brief Any warnings that occurred while sampling heights.
   */
  std::vector<std::string> warnings;
};

} // namespace Cesium3DTilesSelection
