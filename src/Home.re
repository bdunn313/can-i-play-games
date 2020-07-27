let logo: string = [%raw "require('./assets/logo.png')"];

let generateTodos =
    (~len, ~startId=0, ~category: TodoItem.category=Personal, ()) =>
  Belt.Array.range(startId, startId + len)
  ->Belt.Array.map(id =>
      TodoItem.{title: "Something", id, completed: false, category}
    );

[@react.component]
let make = () => {
  let (todos, updateTodos) =
    React.useState(_ =>
      generateTodos(~len=3, ())
      ->Belt.Array.concat(
          generateTodos(~len=1, ~startId=4, ~category=Shared, ()),
        )
      ->Belt.Array.concat(
          generateTodos(~len=4, ~startId=6, ~category=Bonus, ()),
        )
    );
  let toggleById = id =>
    updateTodos(currentTodos =>
      Belt.Array.map(currentTodos, item =>
        switch (item.id == id) {
        | false => item
        | true => {...item, completed: !item.completed}
        }
      )
    );
  <div className=[%tw "h-screen flex justify-center bg-gray-300"]>
    <div className=[%tw "max-w-xl px-4 py-16"]>
      <header>
        <h1 className=[%tw "text-4xl"]>
          {"Before I play games..." |> React.string}
        </h1>
      </header>
      <main>
        <ProgressBar percent=45 />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"I" |> React.string} </span>
          {" need to..." |> React.string}
        </h2>
        <ul>
          {Belt.Array.keep(todos, item => item.category == Personal)
           ->Belt.Array.map(({title, id} as item) =>
               <li key={j|item-$title-$id|j}>
                 <TodoItem item onChange={_ => toggleById(id)} />
               </li>
             )
           |> React.array}
        </ul>
        <hr />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"Someone" |> React.string} </span>
          {" needs to..." |> React.string}
        </h2>
        <ul>
          {Belt.Array.keep(todos, item => item.category == Shared)
           ->Belt.Array.map(({title, id} as item) =>
               <li key={j|item-$title-$id|j}>
                 <TodoItem item onChange={_ => toggleById(id)} />
               </li>
             )
           |> React.array}
        </ul>
        <hr />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"I" |> React.string} </span>
          {" can get bonus time if..." |> React.string}
        </h2>
        <ul>
          {Belt.Array.keep(todos, item => item.category == Bonus)
           ->Belt.Array.map(({title, id} as item) =>
               <li key={j|item-$title-$id|j}>
                 <TodoItem item onChange={_ => toggleById(id)} />
               </li>
             )
           |> React.array}
        </ul>
      </main>
    </div>
  </div>;
};
