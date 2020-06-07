let str = React.string;
let logo: string = [%raw "require('./assets/logo.png')"];

[@react.component]
let make = () =>
  <div className=[%tw "h-screen flex justify-center bg-gray-300"]>
    <div className=[%tw "max-w-xl px-4 py-16"]>
      <header>
        <h1 className=[%tw "text-4xl"]> {"Before I play games..." |> str} </h1>
      </header>
      <main>
        <ProgressBar percent=45 />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"I" |> str} </span>
          {" need to..." |> str}
        </h2>
        <TodoItem title={"Something here" |> str} />
        <hr />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"Someone" |> str} </span>
          {" needs to..." |> str}
        </h2>
        <TodoItem title={"Something here" |> str} />
        <hr />
        <h2 className=[%tw "text-2xl"]>
          <span className=[%tw "italic"]> {"I" |> str} </span>
          {" can get bonus time if..." |> str}
        </h2>
        <TodoItem title={"Something here" |> str} />
      </main>
    </div>
  </div>;
