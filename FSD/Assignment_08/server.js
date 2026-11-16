const express = require("express");
const app = express();

app.use(express.json());

const restaurants = [
  {
    id: 1,
    name: "Spice Garden",
    menu: [
      { item: "Paneer Tikka", price: 220 },
      { item: "Butter Naan", price: 50 },
    ],
  },
  {
    id: 2,
    name: "Pizza Hub",
    menu: [
      { item: "Margherita Pizza", price: 250 },
      { item: "Garlic Bread", price: 120 },
    ],
  },
];

let orders = [];
let nextOrderId = 1;

// Home route
app.get("/", (req, res) => {
  res.json({
    message: "Food Delivery API",
    routes: [
      "GET /restaurants",
      "GET /menu/:restaurantId",
      "POST /order",
      "GET /order/:orderId",
    ],
  });
});

// Display restaurants
app.get("/restaurants", (req, res) => {
  const list = restaurants.map((r) => ({ id: r.id, name: r.name }));
  res.json(list);
});

// View menu of a restaurant
app.get("/menu/:restaurantId", (req, res) => {
  const restaurant = restaurants.find(
    (r) => r.id === Number(req.params.restaurantId)
  );
  if (!restaurant) {
    return res.status(404).json({ error: "Restaurant not found" });
  }
  res.json({ restaurant: restaurant.name, menu: restaurant.menu });
});

// Place an order
app.post("/order", (req, res) => {
  const { restaurantId, item, quantity } = req.body;
  const restaurant = restaurants.find((r) => r.id === Number(restaurantId));

  if (!restaurant) {
    return res.status(404).json({ error: "Restaurant not found" });
  }

  const newOrder = {
    orderId: nextOrderId++,
    restaurant: restaurant.name,
    item,
    quantity: quantity || 1,
    status: "Preparing",
  };

  orders.push(newOrder);
  res.status(201).json({ message: "Order placed!", order: newOrder });
});

// Check order status
app.get("/order/:orderId", (req, res) => {
  const order = orders.find((o) => o.orderId === Number(req.params.orderId));
  if (!order) {
    return res.status(404).json({ error: "Order not found" });
  }
  res.json({ orderId: order.orderId, status: order.status, order });
});

// Handle invalid routes (404)
app.use((req, res) => {
  res.status(404).json({ error: "404 - Route Not Found" });
});

app.listen(3000, () => {
  console.log("Food Delivery Server running on http://localhost:3000");
});

