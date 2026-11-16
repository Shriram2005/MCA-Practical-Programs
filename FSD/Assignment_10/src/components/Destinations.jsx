export default function Destinations() {
  const places = [
    { name: "Goa", info: "Famous for beaches and nightlife." },
    { name: "Manali", info: "Snowy mountains and adventure sports." },
    { name: "Jaipur", info: "Historic forts and royal heritage." },
  ];

  return (
    <div>
      <h2>Popular Destinations</h2>
      <ul>
        {places.map((p) => (
          <li key={p.name}>
            <strong>{p.name}:</strong> {p.info}
          </li>
        ))}
      </ul>
    </div>
  );
}

