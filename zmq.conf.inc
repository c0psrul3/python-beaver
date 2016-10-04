## Default tcp://localhost:2120. Zeromq URL
zeromq_address: 

## Default None. Zeromq HighWaterMark socket option
zeromq_hwm: 

## Default bind. Whether to bind to zeromq host or simply connect
zeromq_bind: 


---

#
# Example 1
#
## Zeromq listening on port 5556 (all interfaces):

# /etc/beaver/conf
[beaver]
zeromq_address: tcp://*:5556

# logstash indexer config:
input {
  zeromq {
    type => 'shipper-input'
    mode => 'client'
    topology => 'pushpull'
    address => 'tcp://shipperhost:5556'
  }
}
output { stdout { debug => true } }

# From the commandline
beaver  -c /etc/beaver/conf -m bind -t zmq


---

#
# Example 2
#
## Zeromq connecting to remote port 5556 on indexer:

# /etc/beaver/conf
[beaver]
zeromq_address: tcp://indexer:5556

# logstash indexer config:
input {
  zeromq {
    type => 'shipper-input'
    mode => 'server'
    topology => 'pushpull'
    address => 'tcp://*:5556'
  }
}
output { stdout { debug => true } }

# on the commandline
beaver -c /etc/beaver/conf -m connect -t zmq


