# GeoIP Tokens

Standalone module that provides tokens with geolocation information - work
in progress.

- Country code `[geoip_tokens:country_code]`
- Latitude `[geoip_tokens:latitude]`
- Longitude `[geoip_tokens:longitude]`
- Timezone name `[geoip_tokens:timezone]`

The information is retrieved from external services, the IP address of
visitors gets anonymized to comply GPDR.

The services (see credits section below) get randomly queried, the result for
the anonymized IP gets cached in a local database for a while, to prevent too
many requests.


## Installation

- Install this module using the
  [official Backdrop CMS instructions](https://backdropcms.org/guide/modules)

No library or binary database file required. This module is really
standalone.


## Issues

Bugs and feature requests should be reported in the
 [Issue Queue](https://github.com/backdrop-contrib/geoip_tokens/issues).


## Current Maintainer

- Indigoxela (https://github.com/indigoxela)


## Credits

Created for Backdrop CMS by Indigoxela

External services in use:

- https://ipapi.co/
- https://reallyfreegeoip.org/
- https://get.geojs.io/


## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
