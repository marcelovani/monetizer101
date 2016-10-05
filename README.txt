
Module: Monetizer101


Description
===========
For Monetizer101 customers:  who want to quickly and easily integrate Monetizer
content in to their site, server-side.


Requirements
============

* Access to Moentizer API


Installation
============

1. Download and enable the module.

3. Configure at Administer > Configuration > System > Monetizer101
 (requires 'Administer Monetizer101 settings' permission)

4. Enable monetizer for each content type you want. Settings for each content type
available in content type setting form Administer > Structure > Conent type > Content_type Name

NOTE: Returned result from Monetizer api is grouped together by merchant. eg if there are 5 result
from amazon and 3 result from Carphone. query will return 2 results from each merchant.
We pass 'group=merchant:2' parameter to query to achieve this.

Implementation
==============

Module provide 2 extra fields and a block.
Extra fields shows product data and block shows a anchor link to extra field.

