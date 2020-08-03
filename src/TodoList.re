[@react.component]
let make = (~todos: array(TodoItem.t), ~toggleById) =>
  <ul className=[%tw "list-none"]>
    {Belt.Array.map(todos, ({title, id} as item) => {
       <TodoItem
         key={j|item-$title-$id|j}
         item
         onChange={_ => toggleById(id)}
       />
     })
     |> React.array}
  </ul>;
