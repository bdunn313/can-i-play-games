type category =
  | Personal
  | Shared
  | Bonus;

type t = {
  id: int,
  title: string,
  completed: bool,
  category,
};

[@react.component]
let make = (~item as {completed, title}, ~onChange) => {
  <li className=[%tw "list-none"]>
    <label className=[%tw "bg-white rounded shadow-xs cursor-pointer"]>
      <input type_="checkbox" onChange checked=completed />
      {title |> React.string}
    </label>
  </li>;
};
