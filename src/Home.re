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

  let percentDone =
    React.useMemo1(
      () => {
        let nonBonus = Belt.Array.keep(todos, x => x.category != Bonus);
        let completed =
          Belt.Array.keep(nonBonus, x => x.completed)->Belt.Array.length;
        let total = Belt.Array.length(nonBonus);
        let percentage =
          floor(float_of_int(completed) /. float_of_int(total) *. 100.);
        int_of_float(percentage);
      },
      [|todos|],
    );
  let canPlayGames =
    React.useMemo1(() => percentDone >= 100, [|percentDone|]);

  <div className=[%tw "h-screen flex justify-center bg-gray-300"]>
    <div className=[%tw "max-w-xl px-4 py-16"]>
      <header>
        <h1 className=[%tw "text-4xl"]>
          {"I " |> React.string}
          <em className=[%tw "italic"]>
            {(canPlayGames ? "Can" : "Cannot") |> React.string}
          </em>
          {" Play Games!" |> React.string}
        </h1>
      </header>
      <main>
        <ProgressBar percent=percentDone />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"I" |> React.string} </span>
          {" need to..." |> React.string}
        </h2>
        <TodoList
          todos={Belt.Array.keep(todos, item => item.category == Personal)}
          toggleById
        />
        <hr />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"Someone" |> React.string} </span>
          {" needs to..." |> React.string}
        </h2>
        <TodoList
          todos={Belt.Array.keep(todos, item => item.category == Shared)}
          toggleById
        />
        <hr />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"I" |> React.string} </span>
          {" can get bonus time if..." |> React.string}
        </h2>
        <TodoList
          todos={Belt.Array.keep(todos, item => item.category == Bonus)}
          toggleById
        />
      </main>
    </div>
  </div>;
};
