<?php
/**
 * @file Token definitions of module.
 */

/**
 * Implements hook_token_info().
 */
function geoip_tokens_token_info() {
  $type = array(
    'name' => t('GeoIP data'),
    'description' => t('Tokens related to geolocation info based on anonymized IP of visitor or user.'),
  );

  $tokens['country_code'] = array(
    'name' => t('Country code'),
    'description' => t('The country code (two letters) of the current visitors position.'),
  );
  $tokens['latitude'] = array(
    'name' => t('Latitude'),
    'description' => t('The latitude of the current visitors position.'),
  );
  $tokens['longitude'] = array(
    'name' => t('Longitude'),
    'description' => t('The longitude of the current visitors position.'),
  );
  $tokens['timezone'] = array(
    'name' => t('Timezone'),
    'description' => t('The timezone name in use at the current visitors position.'),
  );

  return array(
    'types' => array('geoip_tokens' => $type),
    'tokens' => array('geoip_tokens' => $tokens),
  );
}

/**
 * Implements hook_tokens().
 */
function geoip_tokens_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'geoip_tokens') {
    $info = geoip_tokens_get_geoip_info();
    if (!$info) {
      // Jump out early if the (external) request failed.
      return $replacements;
    }
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'country_code':
          $replacements[$original] = $info['country_code'];
          break;

        case 'latitude':
          $replacements[$original] = $info['latitude'];
          break;

        case 'longitude':
          $replacements[$original] = $info['longitude'];
          break;

        case 'timezone':
          $replacements[$original] = $info['timezone'];
          break;
      }
    }
  }
  return $replacements;
}
