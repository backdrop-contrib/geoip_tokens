(function ($) {

  'use strict';

  Backdrop.geoipTokens = {};

/**
 * To make use of Backdrop.geoipTokens.getData():
 *
 * Backdrop.geoipTokens.getData('latlon').success(function (data) {
 *   // Your callback here.
 * });
 *
 * Available types:
 * - latlon: latitude and longitude
 * - ccode: country code (uppercase)
 * - tzone: timezone name
 */

  Backdrop.geoipTokens.getData = function (type) {
    return $.ajax({
      url: Backdrop.settings.basePath + 'geoip-tokens/ajax/' + type,
      type: 'POST',
      dataType: 'json',
      data: {
        geoipTokenRequestToken: Backdrop.settings.geoipToken
      }
    });
  }

})(jQuery);
