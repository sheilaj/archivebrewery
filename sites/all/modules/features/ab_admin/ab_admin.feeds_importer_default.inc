<?php
/**
 * @file
 * ab_admin.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ab_admin_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'beer';
  $feeds_importer->config = array(
    'name' => 'beer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'beer',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'abv',
            'target' => 'field_abv',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'style',
            'target' => 'field_style',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          3 => array(
            'source' => 'brewery',
            'target' => 'field_brewery:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'beer',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['beer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'breweries';
  $feeds_importer->config = array(
    'name' => 'breweries',
    'description' => 'Import breweries',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'brewery',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'country',
            'target' => 'field_location:country',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'region',
            'target' => 'field_location:administrative_area',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'city',
            'target' => 'field_location:locality',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'premise',
            'target' => 'field_location:premise',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'brewery',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['breweries'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'items';
  $feeds_importer->config = array(
    'name' => 'items',
    'description' => 'Import items',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'type',
            'target' => 'field_item_type',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          1 => array(
            'source' => 'story',
            'target' => 'field_private_notes',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'features',
            'target' => 'field_descriptors',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          3 => array(
            'source' => 'beer',
            'target' => 'field_beer:label',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'title',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'capacity',
            'target' => 'field_format',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'features2',
            'target' => 'field_descriptors',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          7 => array(
            'source' => 'colour',
            'target' => 'field_bottle_colour',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'item',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['items'] = $feeds_importer;

  return $export;
}
