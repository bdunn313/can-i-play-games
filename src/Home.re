let str = React.string;
let logo: string = [%raw "require('./assets/logo.png')"];

[@react.component]
let make = () =>
  <div className="h-screen flex justify-center bg-gray-300">
    <div className="max-w-xl px-4 py-16">
      <header>
        <h1 className="text-4xl"> {"Before I play games..." |> str} </h1>
      </header>
      <main>
        <ProgressBar percent=45 />
        <h2 className="text-2xl">
          <span className="italic"> {"I" |> str} </span>
          {" need to..." |> str}
        </h2>
        <TodoItem title={"Something here" |> str} />
        <hr />
        <h2 className="text-2xl">
          <span className="italic"> {"Someone" |> str} </span>
          {" needs to..." |> str}
        </h2>
        <TodoItem title={"Something here" |> str} />
        <hr />
        <h2 className="text-2xl">
          <span className="italic"> {"I" |> str} </span>
          {" can get bonus time if..." |> str}
        </h2>
        <TodoItem title={"Something here" |> str} />
      </main>
    </div>
  </div>;
