import { useEffect, useState } from "react";

const API_URL = "http://localhost:5000/todos";

export default function App() {
  const [todos, setTodos] = useState([]);
  const [text, setText] = useState("");

  const fetchTodos = async () => {
    const res = await fetch(API_URL);
    const data = await res.json();
    setTodos(data);
  };

  useEffect(() => {
    fetchTodos();
  }, []);

  const addTodo = async (e) => {
    e.preventDefault();
    if (!text.trim()) return;

    await fetch(API_URL, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ text }),
    });
    setText("");
    fetchTodos();
  };

  const toggleTodo = async (id) => {
    await fetch(`${API_URL}/${id}`, { method: "PUT" });
    fetchTodos();
  };

  const deleteTodo = async (id) => {
    await fetch(`${API_URL}/${id}`, { method: "DELETE" });
    fetchTodos();
  };

  return (
    <div style={{ fontFamily: "sans-serif", padding: "20px", maxWidth: "450px" }}>
      <h2>ToDo App (React + MongoDB)</h2>

      <form onSubmit={addTodo} style={{ marginBottom: "15px" }}>
        <input
          type="text"
          placeholder="Enter a task..."
          value={text}
          onChange={(e) => setText(e.target.value)}
        />{" "}
        <button type="submit">Add</button>
      </form>

      <ul>
        {todos.map((todo) => (
          <li key={todo._id} style={{ marginBottom: "8px" }}>
            <span
              onClick={() => toggleTodo(todo._id)}
              style={{
                cursor: "pointer",
                textDecoration: todo.completed ? "line-through" : "none",
              }}
            >
              {todo.text}
            </span>{" "}
            <button onClick={() => deleteTodo(todo._id)}>Delete</button>
          </li>
        ))}
      </ul>
    </div>
  );
}

