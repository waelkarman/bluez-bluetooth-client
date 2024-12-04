# bluetooth-service
interact with the Bluetooth devices through the D-Bus interface

```
busctl list | grep bluez
busctl tree org.bluez
busctl introspect org.bluez /org/bluez/hci0
```
```
wael.karman@waelkarman:~$ busctl introspect org.bluez /org/bluez/hci0
NAME                                TYPE      SIGNATURE RESULT/VALUE                             FLAGS
org.bluez.Adapter1                  interface -         -                                        -
.GetDiscoveryFilters                method    -         as                                       -
.RemoveDevice                       method    o         -                                        -
.SetDiscoveryFilter                 method    a{sv}     -                                        -
.StartDiscovery                     method    -         -                                        -
.StopDiscovery                      method    -         -                                        -
.Address                            property  s         "4C:49:6C:4E:A3:DA"                      emits-change
.AddressType                        property  s         "public"                                 emits-change
.Alias                              property  s         "ar-lx0275"                              emits-change writable
.Class                              property  u         8126732                                  emits-change
.Discoverable                       property  b         false                                    emits-change writable
.DiscoverableTimeout                property  u         180                                      emits-change writable
.Discovering                        property  b         false                                    emits-change
.ExperimentalFeatures               property  as        -                                        emits-change
.Modalias                           property  s         "usb:v1D6Bp0246d0540"                    emits-change
.Name                               property  s         "ar-lx0275"                              emits-change
.Pairable                           property  b         false                                    emits-change writable
.PairableTimeout                    property  u         0                                        emits-change writable
.Powered                            property  b         true                                     emits-change writable
.Roles                              property  as        2 "central" "peripheral"                 emits-change
.UUIDs                              property  as        17 "00001133-0000-1000-8000-00805f9b34f… emits-change
org.bluez.GattManager1              interface -         -                                        -
.RegisterApplication                method    oa{sv}    -                                        -
.UnregisterApplication              method    o         -                                        -
org.bluez.LEAdvertisingManager1     interface -         -                                        -
.RegisterAdvertisement              method    oa{sv}    -                                        -
.UnregisterAdvertisement            method    o         -                                        -
.ActiveInstances                    property  y         0                                        emits-change
.SupportedIncludes                  property  as        3 "tx-power" "appearance" "local-name"   emits-change
.SupportedInstances                 property  y         12                                       emits-change
.SupportedSecondaryChannels         property  as        3 "1M" "2M" "Coded"                      emits-change
org.bluez.Media1                    interface -         -                                        -
.RegisterApplication                method    oa{sv}    -                                        -
.RegisterEndpoint                   method    oa{sv}    -                                        -
.RegisterPlayer                     method    oa{sv}    -                                        -
.UnregisterApplication              method    o         -                                        -
.UnregisterEndpoint                 method    o         -                                        -
.UnregisterPlayer                   method    o         -                                        -
org.bluez.NetworkServer1            interface -         -                                        -
.Register                           method    ss        -                                        -
.Unregister                         method    s         -                                        -
org.freedesktop.DBus.Introspectable interface -         -                                        -
.Introspect                         method    -         s                                        -
org.freedesktop.DBus.Properties     interface -         -                                        -
.Get                                method    ss        v                                        -
.GetAll                             method    s         a{sv}                                    -
.Set                                method    ssv       -                                        -
.PropertiesChanged                  signal    sa{sv}as  -                                        -
```

