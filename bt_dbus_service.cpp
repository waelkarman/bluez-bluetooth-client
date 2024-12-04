#include <gio/gio.h>
#include <iostream>
#include <string>

using namespace std; 

#include <gio/gio.h>
#include <iostream>
#include <string>

class bt_service_dbus {

public:
    bt_service_dbus() {
        GError *error = nullptr;

        connection = g_bus_get_sync(G_BUS_TYPE_SYSTEM, nullptr, &error);
        if (!connection) {
            std::cerr << "Failed to connect to the system bus: " << error->message << std::endl;
            g_error_free(error);
        } else {
            std::cout << "Connected to the D-Bus" << std::endl;
        }
    }

    std::string getName() {
        GError *error = nullptr;
        const gchar *interface_name = "org.bluez.Adapter1";
        const gchar *property_name = "Name";

        GVariant *result = g_dbus_connection_call_sync(
            connection,
            "org.bluez",
            "/org/bluez/hci0",
            "org.freedesktop.DBus.Properties",
            "Get",
            g_variant_new("(ss)", interface_name, property_name),
            nullptr,
            G_DBUS_CALL_FLAGS_NONE,
            -1,
            nullptr,
            &error
        );

        if (error != nullptr) {
            std::cerr << "Failed to call method: " << error->message << std::endl;
            g_error_free(error);
            return "";
        }


        if (result == nullptr) {
            std::cerr << "D-Bus call returned nullptr" << std::endl;
            return "";
        }

        GVariant *inner_variant = nullptr;
        g_variant_get(result, "(v)", &inner_variant);

        const gchar *name = nullptr;
        g_variant_get(inner_variant, "s", &name);

        std::string adapter_name(name);

        g_variant_unref(inner_variant);
        g_variant_unref(result);

        std::cout << "Bluetooth adapter name: " << adapter_name << std::endl;

        return adapter_name;
    }

    ~bt_service_dbus() {
        if (connection != nullptr) {
            g_object_unref(connection);
        }
    }

private:
    GDBusConnection *connection = nullptr;
};



int main() {
    bt_service_dbus bt;
    bt.getName();



    return 0;
}
