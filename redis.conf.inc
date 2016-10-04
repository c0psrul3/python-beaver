
## Default redis://localhost:6379/0. Comma separated redis URLs
redis_url: 
## Default logstash:beaver. Redis key namespace
redis_namespace: 
## Default list, but can also be channel. Redis data type used for transporting log messages
redis_data_type: 


#
# Example
# -------
## Sending logs from /var/log files to a redis list:

# /etc/beaver/conf
[beaver]
redis_url: redis://localhost:6379/0

# From the commandline
beaver  -c /etc/beaver/conf -t redis

