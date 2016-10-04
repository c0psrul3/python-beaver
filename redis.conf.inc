
## Default redis://localhost:6379/0. Comma separated redis URLs
redis_url: 
## Default logstash:beaver. Redis key namespace
redis_namespace: 
## Default list, but can also be channel. Redis data type used for transporting log messages
redis_data_type: 


#
# Example 1
#
## Sending logs from /var/log files to a redis list:

# /etc/beaver/conf
[beaver]
redis_url: redis://localhost:6379/0

# From the commandline
beaver  -c /etc/beaver/conf -t redis


---

#
# Example 2
#
## Sending logs from /var/log files to multiple redis servers using round robin strategy:

# /etc/beaver/conf
[beaver]
redis_url: redis://broker01:6379/0,redis://broker02:6379/0,redis://broker03:6379/0

# From the commandline
beaver  -c /etc/beaver/conf -t redis


---

#
# Example 3
#
## Sending logs from /tmp/somefile files to a redis list, with custom namespace:

# /etc/beaver/conf
[beaver]
redis_url: redis://localhost:6379/0

[/tmp/somefile]
type: mytype
tags: tag1,tag2
redis_namespace: some:space

# From the commandline
beaver  -c /etc/beaver/conf -t redis


