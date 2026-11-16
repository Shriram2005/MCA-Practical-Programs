import { useState } from "react";

export default function BookingForm({ selectedPackage }) {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [pkg, setPkg] = useState(selectedPackage);
  const [travelers, setTravelers] = useState(1);
  const [submitted, setSubmitted] = useState(null);

  const handleSubmit = (e) => {
    e.preventDefault();
    setSubmitted({ name, email, pkg, travelers });
  };

  return (
    <div>
      <h2>Book Your Trip</h2>
      <form onSubmit={handleSubmit}>
        <p>
          Name:{" "}
          <input
            type="text"
            required
            value={name}
            onChange={(e) => setName(e.target.value)}
          />
        </p>
        <p>
          Email:{" "}
          <input
            type="email"
            required
            value={email}
            onChange={(e) => setEmail(e.target.value)}
          />
        </p>
        <p>
          Package:{" "}
          <select value={pkg} onChange={(e) => setPkg(e.target.value)}>
            <option>Goa Beach Getaway</option>
            <option>Manali Snow Adventure</option>
            <option>Jaipur Heritage Tour</option>
          </select>
        </p>
        <p>
          Travelers:{" "}
          <input
            type="number"
            min="1"
            value={travelers}
            onChange={(e) => setTravelers(e.target.value)}
          />
        </p>
        <button type="submit">Submit Booking</button>
      </form>

      {submitted && (
        <div style={{ marginTop: "15px", color: "green" }}>
          <strong>Booking Request Submitted!</strong>
          <p>
            {submitted.name} ({submitted.email}) booked "{submitted.pkg}" for{" "}
            {submitted.travelers} traveler(s).
          </p>
        </div>
      )}
    </div>
  );
}

