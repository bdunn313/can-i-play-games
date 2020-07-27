[@react.component]
let make = (~todos: array(TodoItem.t), ~toggleById) =>
  <ul>
    {Belt.Array.map(todos, ({title, id} as item) => {
       <li key={j|item-$title-$id|j}>
         <TodoItem item onChange={_ => toggleById(id)} />
       </li>
     })
     |> React.array}
  </ul>;
