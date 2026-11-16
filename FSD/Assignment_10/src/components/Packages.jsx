import { useState } from "react";

const packageList = [
  {
    id: 1,
    name: "Goa Beach Getaway",
    days: "3 Days / 2 Nights",
    price: 12000,
    details: "Includes hotel stay, breakfast, and North Goa sightseeing.",
  },
  {
    id: 2,
    name: "Manali Snow Adventure",
    days: "5 Days / 4 Nights",
    price: 18500,
    details: "Includes Volvo bus, resort stay, and Solang Valley tour.",
  },
  {
    id: 3,
    name: "Jaipur Heritage Tour",
    days: "4 Days / 3 Nights",
    price: 15000,
    details: "Includes Amer Fort visit, cultural dinner, and city guide.",
  },
];

export default function Packages({ onBook }) {
  const [activePkg, setActivePkg] = useState(null);

  return (
    <div>
      <h2>Tour Packages</h2>
      {packageList.map((pkg) => (
        <div
          key={pkg.id}
          style={{ border: "1px solid #ccc", padding: "10px", marginBottom: "10px" }}
        >
          <h3>{pkg.name}</h3>
          <p>{pkg.days} - Rs. {pkg.price}</p>
          <button onClick={() => setActivePkg(pkg)}>View Details</button>{" "}
          <button onClick={() => onBook(pkg.name)}>Book Now</button>
        </div>
      ))}

      {activePkg && (
        <div style={{ marginTop: "15px", padding: "10px", background: "#f4f4f4" }}>
          <h3>Package Details: {activePkg.name}</h3>
          <p>Duration: {activePkg.days}</p>
          <p>Price: Rs. {activePkg.price}</p>
          <p>{activePkg.details}</p>
        </div>
      )}
    </div>
  );
}

