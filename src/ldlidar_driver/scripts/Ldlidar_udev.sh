echo  'KERNEL=="ttyUSB*", ATTRS{idVendor}=="10c4", ATTRS{idProduct}=="ea60",ATTRS{serial}=="0001", MODE:="0777", GROUP:="dialout", SYMLINK+="ldlidar_serial"' >/etc/udev/rules.d/ldlidar_driver.rules

service udev reload
sleep 2
service udev restart


