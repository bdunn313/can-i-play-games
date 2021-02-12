let generateTodos = (~len, ~startId=0, ~category: TodoItem.category=Personal, ()) =>
  Belt.Array.range(startId, startId + len)->Belt.Array.map(id => {
    open TodoItem
    {title: "Something", id: id, completed: false, category: category}
  })

@react.component
let make = () => {
  let (todos, updateTodos) = React.useState(_ =>
    generateTodos(~len=1, ())
    ->Belt.Array.concat(generateTodos(~len=0, ~startId=4, ~category=Shared, ()))
    ->Belt.Array.concat(generateTodos(~len=4, ~startId=6, ~category=Bonus, ()))
  )

  let toggleById = id =>
    updateTodos(currentTodos =>
      Belt.Array.map(currentTodos, item =>
        switch item.id == id {
        | false => item
        | true => {...item, completed: !item.completed}
        }
      )
    )

  <div className=%tw("h-screen flex flex-col items-stretch bg-gray-300 m-0")>
    <Header todos />
    <main className=%tw("px-4 py-16")>
      <TodoList
        title="I need to..."
        todos={Belt.Array.keep(todos, item => item.category == Personal)}
        toggleById
      />
      <TodoList
        title="Someone needs to..."
        todos={Belt.Array.keep(todos, item => item.category == Shared)}
        toggleById
      />
      <TodoList
        title="I can get bonus time if I..."
        todos={Belt.Array.keep(todos, item => item.category == Bonus)}
        toggleById
      />
    </main>
  </div>
}
