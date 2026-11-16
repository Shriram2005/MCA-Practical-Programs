export default function Home({ onExplore }) {
  return (
    <div>
      <h2>Welcome to EasyTravel</h2>
      <p>Explore amazing destinations and book affordable tour packages.</p>
      <button onClick={onExplore}>View Tour Packages</button>
    </div>
  );
}

