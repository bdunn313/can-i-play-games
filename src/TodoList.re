[@react.component]
let make = (~todos: array(TodoItem.t), ~toggleById, ~title) =>
  <section>
    <header className=[%tw "mt-6 mb-1"]>
      <h2 className=[%tw "text-2xl"]> {title |> React.string} </h2>
    </header>
    <ul className=[%tw "list-none"]>
      {Belt.Array.map(todos, ({title, id} as item) => {
         <li key={j|item-$title-$id|j} className=[%tw "mb-2"]>
           <TodoItem item onChange={_ => toggleById(id)} />
         </li>
       })
       |> React.array}
    </ul>
  </section>;
