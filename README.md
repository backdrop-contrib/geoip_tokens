# GeoIP Tokens

Standalone module that provides tokens with geolocation information based on
IP addresses.

- Country code `[geoip_tokens:country_code]`
- Latitude `[geoip_tokens:latitude]`
- Longitude `[geoip_tokens:longitude]`
- Timezone name `[geoip_tokens:timezone]`

The information is retrieved from external services, the IP addresses get 
anonymized to comply with GPDR.

To make use of this module, your Backdrop site must be able to do external
requests - which is usually the case.

The services (see credits section below) get randomly queried, the results for
the anonymized IPs get cached in a local database for a while, to prevent too
many requests.

### Precision of results

The results are not as exact as, for instance, GPS. Geolocation based on IP
addresses can only be approximate. The results may even be wrong for a
while, until a service provider updates outdated information.

### Use cases

Typical use-cases are sites that provide services that need some infos about
the visitor's or user's position.

For example, to center a map, to redirect to specific pages for different 
countries or to display dates in the proper timezone.

### When _not_ to use this module

This module has been written with low- to medium-traffic sites in mind. If your 
site has really high traffic on pages that use the tokens, you might easily 
burst the (generous) limits of the providers in use. Although this module tries 
to distribute the load and to cache locally. "High traffic" means: thousands of
requests per day.

### Rules support

Additionally to the tokens, this module also ships with Rules support.
Two conditions are available:

- Compare the current IP with a configurable list of countries
- Check if current IP is within the European Union

### For developers

While tokens can be helpful, you might need something more special, like
juggling with data via hook_form_alter().

In this case use the function geoip_tokens_get_geoip_info() directly. Its
optional parameter can be one of:

- all (the default)
- latlon
- country_code
- timezone

You get a keyed array of values.

If you need to get things working with cached pages and anonymous users, use the
ajax API. See the example in js/geoip_tokens.js, note that the ajax
parameters are slightly different.

```
Backdrop.geoipTokens.getData('ccode').success(function (data) {
  // Your callback here.
  // "data" contains the values you requested.
});
```


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
- https://www.geojs.io/
- https://freegeoip.app/
- https://freegeoip.live/
- https://geoiplookup.io/


## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
