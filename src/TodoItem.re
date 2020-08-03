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
  <label
    className=[%tw
      "flex justify-start items-start border rounded px-2 py-5 bg-white shadow-sm cursor-pointer select-none"
    ]>
    <div
      className=[%tw
        "bg-white border-2 rounded w-6 h-6 justify-center items-center mr-2"
      ]>
      <input
        type_="checkbox"
        onChange
        checked=completed
        className=[%tw "h-5 w-5 text-gray-600"]
      />
    </div>
    {title |> React.string}
  </label>;
};
