import ListGroup from "./components/ListGroup";

function App(){
  let items = ["Delhi", "Mumbai", "Chennai", "Kolkata", "Lucknow"];

  return <div><ListGroup items={items} heading="Cities" /></div>;
}

export default App;