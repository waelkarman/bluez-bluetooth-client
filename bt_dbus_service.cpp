#include <gio/gio.h>
#include <iostream>
#include <string>

int main() {
    GError *error = nullptr;

    GDBusConnection *connection = g_bus_get_sync(G_BUS_TYPE_SYSTEM, nullptr, &error);
    if (error != nullptr) {
        std::cerr << "Failed to connect to the bus: " << error->message << std::endl;
        g_error_free(error);
        return 1;
    }

    const gchar *interface_name = "org.bluez.Adapter1";
    const gchar *property_name = "Name";

    GVariant *result = g_dbus_connection_call_sync(
        connection,
        "org.bluez",
        "/org/bluez/hci0",
        "org.freedesktop.DBus.Properties",
        "Get",
        g_variant_new("(ss)", interface_name, property_name),
        G_VARIANT_TYPE("(v)"),
        G_DBUS_CALL_FLAGS_NONE,
        -1,
        nullptr,
        &error
    );

    if (error != nullptr) {
        std::cerr << "Failed to call method: " << error->message << std::endl;
        g_error_free(error);
        return 1;
    }
   

    GVariant *inner_variant = nullptr;
    g_variant_get(result, "(v)", &inner_variant);


    const gchar *name = nullptr;
    g_variant_get(inner_variant, "s", &name);


    std::cout << "Bluetooth adapter name: " << name << std::endl;


    g_variant_unref(result);
    g_object_unref(connection);

    return 0;
}
