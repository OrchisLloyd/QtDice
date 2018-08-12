export PATH=/usr/local/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

export XDG_DATA_DIRS=/usr/local/share:${XDG_DATA_DIRS:-/usr/local/share/:/usr/share/}
export XDG_CONFIG_DIRS=/usr/local/etc/xdg:${XDG_CONFIG_DIRS:-/etc/xdg}

export QT_PLUGIN_PATH=/usr/local/lib/plugins:$QT_PLUGIN_PATH
export QML2_IMPORT_PATH=/usr/local/lib/qml:$QML2_IMPORT_PATH
