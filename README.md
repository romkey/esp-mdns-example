# Minimal mDNS Example for ESP8266 and ESP32

This repo contains an example of the minimal code needed to set up mDNS using the Arduino Core on the ESP8266 and the ESP32.

I build using PlatformIO but you can just create an Arduino IDE project and copy the contents of `main.cpp` into it to build using it.

## ESP32

The ESP32 code works. I'm able to ping `chicken32.local` from my Mac.

## ESP8266

The ESP8266 code does not work. I'm not able to ping or otherwise resolve `chicken8266.local`. Doing a packet trace using `tcpdump` shows no traffic from the ESP8266.

I do see this output from the ESP8266:

```
IP address: 10.0.1.152
mDNS responder started
[MDNSResponder] _parseQuery: Possible race-condition for host domain detected while probing.
[MDNSResponder] _parseQuery: Possible race-condition for host domain detected while probing.
[MDNSResponder] _parseQuery: Possible race-condition for host domain detected while probing.
```

It appears that its mDNS implementation gets stuck in the initial probing state and never completes it.
