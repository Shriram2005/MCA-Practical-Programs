import { useState } from "react";
import Home from "./components/Home.jsx";
import Destinations from "./components/Destinations.jsx";
import Packages from "./components/Packages.jsx";
import BookingForm from "./components/BookingForm.jsx";
import Contact from "./components/Contact.jsx";

export default function App() {
  const [page, setPage] = useState("home");
  const [selectedPackage, setSelectedPackage] = useState("Goa Beach Getaway");

  const handleBookPackage = (packageName) => {
    setSelectedPackage(packageName);
    setPage("booking");
  };

  return (
    <div style={{ fontFamily: "sans-serif", padding: "20px" }}>
      <h1>Travel Booking System</h1>

      <nav style={{ marginBottom: "20px", display: "flex", gap: "10px" }}>
        <button onClick={() => setPage("home")}>Home</button>
        <button onClick={() => setPage("destinations")}>Destinations</button>
        <button onClick={() => setPage("packages")}>Packages</button>
        <button onClick={() => setPage("booking")}>Booking Form</button>
        <button onClick={() => setPage("contact")}>Contact</button>
      </nav>

      {page === "home" && <Home onExplore={() => setPage("packages")} />}
      {page === "destinations" && <Destinations />}
      {page === "packages" && <Packages onBook={handleBookPackage} />}
      {page === "booking" && <BookingForm selectedPackage={selectedPackage} />}
      {page === "contact" && <Contact />}
    </div>
  );
}

