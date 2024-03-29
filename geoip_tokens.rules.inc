<?php
/**
 * @file
 * GeoIP Token support code for the Rules module.
 */

/**
 * Implements hook_rules_data_info().
 */
function geoip_tokens_rules_data_info() {
  return array(
    'geoip_tokens' => array(
      'label' => 'geoip token',
      'type' => 'geoip_tokens',
      'token type' => 'geoip_tokens',
      'ui class' => 'RulesDataUIText',
      'property info' => _geoip_tokens_tokens_info(),
    ),
  );
}

/**
 * Helper function to declare the token type to rules.
 */
function _geoip_tokens_tokens_info() {
  return array(
    'country_code' => array(
      'label' => t('Country code'),
      'description' => t('Country code (two uppercase letters) detected by current IP.'),
      'type' => 'text',
    ),
    'timezone' => array(
      'label' => t('Timezone'),
      'description' => t('Timezone name detected by current IP'),
      'type' => 'text',
    ),
    'latitude' => array(
      'label' => t('Latitude'),
      'description' => t('Latitude of current position detected by IP'),
      'type' => 'decimal',
    ),
    'longitude' => array(
      'label' => t('Longitude'),
      'description' => t('Longitude of current position detected by IP'),
      'type' => 'decimal',
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 *
 * Condition to compare if the detected country is contained in a list of
 * selected countries.
 */
function geoip_tokens_rules_condition_info() {
  return array(
    'geoip_tokens_rules_condition_country_compare' => array(
      'label' => t('Check for user country detected by IP'),
      'parameter' => array(
        'Countries' => array(
          'label' => t('Country'),
          'type' => 'list<text>',
          'restriction' => 'input',
          'options list' => 'geoip_tokens_countries_list',
        ),
      ),
      'group' => t('GeoIP Tokens'),
    ),
    'geoip_tokens_rules_condition_is_european_union' => array(
      'label' => t('Check if detected country is in the European Union'),
      'group' => t('GeoIP Tokens'),
    ),
  );
}

/**
 * Checks if the detected country matches to one in the list.
 *
 * @param array $countries
 *   List of countries to check against.
 *
 * @return bool
 *   TRUE if the country code is in the list.
 */
function geoip_tokens_rules_condition_country_compare($countries) {
  if (!is_array($countries)) {
    $countries = explode('\n', strtoupper($countries));
  }
  $current_country = geoip_tokens_get_geoip_info('country_code');
  return in_array($current_country['country_code'], $countries);
}

/**
 * Checks if the detected country is a member of the European Union.
 */
function geoip_tokens_rules_condition_is_european_union() {
  $current_country = geoip_tokens_get_geoip_info('country_code');
  $members = geoip_tokens_eu_member_list();
  return in_array($current_country['country_code'], $members);
}

/**
 * Helper function to provide an options list for rules UI.
 */
function geoip_tokens_countries_list() {
  include_once BACKDROP_ROOT . '/core/includes/locale.inc';
  return country_get_list();
}

/**
 * Helper function to provide a list of member countries.
 */
function geoip_tokens_eu_member_list() {
  $member_countries = array(
    'AT',
    'BE',
    'BG',
    'CY',
    'CZ',
    'DE',
    'DK',
    'EE',
    'ES',
    'FI',
    'FR',
    'GR',
    'HR',
    'HU',
    'IE',
    'IT',
    'LT',
    'LU',
    'LV',
    'MT',
    'NL',
    'PL',
    'PT',
    'RO',
    'SE',
    'SI',
    'SK',
  );
  return $member_countries;
}
