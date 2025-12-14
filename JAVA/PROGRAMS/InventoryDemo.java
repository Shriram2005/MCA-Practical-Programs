/* Smart Inventory & Warehouse Automation System - simplified demo */

import java.util.*;

class Item {
    String sku;
    String name;
    String category;
    String supplier;
    int threshold; // restock threshold

    public Item(String sku, String name, String category, String supplier, int threshold) {
        this.sku = sku; this.name = name; this.category = category; this.supplier = supplier; this.threshold = threshold;
    }
}

class Warehouse {
    String id;
    String location;
    Map<String,Integer> stock = new HashMap<>(); // sku -> quantity

    public Warehouse(String id, String location) { this.id = id; this.location = location; }

    public void addStock(String sku, int qty) {
        stock.put(sku, stock.getOrDefault(sku,0) + qty);
    }

    public boolean removeStock(String sku, int qty) {
        int available = stock.getOrDefault(sku,0);
        if (available >= qty) {
            stock.put(sku, available - qty);
            return true;
        }
        return false;
    }

    public int getStock(String sku) { return stock.getOrDefault(sku,0); }
}

class InventorySystem {
    Map<String,Item> items = new HashMap<>();
    Map<String,Warehouse> warehouses = new HashMap<>();
    List<String> movementHistory = new ArrayList<>();

    // Add, update, remove item
    public void addItem(Item it) { items.put(it.sku, it); }
    public void updateItem(String sku, String name) { if (items.containsKey(sku)) items.get(sku).name = name; }
    public void removeItem(String sku) { items.remove(sku); }

    // Warehouse operations
    public void addWarehouse(Warehouse w) { warehouses.put(w.id, w); }

    // Stock operations across warehouses
    public int totalStock(String sku) {
        int total = 0;
        for (Warehouse w : warehouses.values()) total += w.getStock(sku);
        return total;
    }

    // Auto-restock check (simple print suggestion)
    public void checkRestock(String sku) {
        Item it = items.get(sku);
        if (it == null) return;
        int total = totalStock(sku);
        if (total < it.threshold) {
            movementHistory.add("Auto-restock triggered for " + sku + " (stock=" + total + ", threshold=" + it.threshold + ")");
            System.out.println("Auto-restock: order placed for SKU " + sku + " (current stock " + total + ")");
        }
    }

    // Reservation during checkout
    public boolean reserve(String warehouseId, String sku, int qty) {
        Warehouse w = warehouses.get(warehouseId);
        if (w == null) return false;
        if (w.getStock(sku) >= qty) {
            w.removeStock(sku, qty); // reserve by removing from stock
            movementHistory.add("Reserved " + qty + " of " + sku + " at " + warehouseId);
            checkRestock(sku);
            return true;
        }
        return false;
    }

    public void releaseReservation(String warehouseId, String sku, int qty) {
        Warehouse w = warehouses.get(warehouseId);
        if (w == null) return;
        w.addStock(sku, qty);
        movementHistory.add("Released reservation of " + qty + " of " + sku + " at " + warehouseId);
    }

    // Simple purchase order handling: receive shipment to a warehouse
    public void receiveShipment(String warehouseId, String sku, int qty) {
        Warehouse w = warehouses.get(warehouseId);
        if (w == null) return;
        w.addStock(sku, qty);
        movementHistory.add("Received shipment: " + qty + " of " + sku + " at " + warehouseId);
    }

    // Reports
    public void printStockReport() {
        System.out.println("=== Stock Report ===");
        for (String sku : items.keySet()) {
            System.out.println("SKU: " + sku + " | Total stock: " + totalStock(sku));
        }
    }

    public void printMovementHistory() {
        System.out.println("=== Movement History ===");
        for (String s : movementHistory) System.out.println(s);
    }
}

public class InventoryDemo {
    public static void main(String[] args) {
        InventorySystem sys = new InventorySystem();

        // create items
        sys.addItem(new Item("SKU1", "Wireless Mouse", "Electronics", "SupplierA", 10));
        sys.addItem(new Item("SKU2", "USB Cable", "Accessories", "SupplierB", 20));

        // create warehouses
        Warehouse w1 = new Warehouse("W1", "Pune");
        Warehouse w2 = new Warehouse("W2", "Mumbai");
        sys.addWarehouse(w1); sys.addWarehouse(w2);

        // initial stock
        w1.addStock("SKU1", 5);
        w2.addStock("SKU1", 3);
        w1.addStock("SKU2", 50);

        // display stock
        sys.printStockReport();

        // simulate reservation/checkout (avoiding oversell)
        System.out.println("\nCustomer attempts to reserve 6 of SKU1 at W1:");
        boolean reserved = sys.reserve("W1", "SKU1", 6);
        System.out.println("Reservation success: " + reserved);

        System.out.println("\nReserve 3 of SKU1 at W2:");
        reserved = sys.reserve("W2", "SKU1", 3);
        System.out.println("Reservation success: " + reserved);

        // receive shipment (purchase order fulfilled)
        System.out.println("\nReceiving shipment of 20 SKU1 to W1");
        sys.receiveShipment("W1", "SKU1", 20);

        // final reports
        System.out.println();
        sys.printStockReport();
        System.out.println();
        sys.printMovementHistory();
    }
}
