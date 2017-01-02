<?php
/**
 * @file
 * ab_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ab_admin_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
