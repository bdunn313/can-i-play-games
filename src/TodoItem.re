let str = React.string;

[@react.component]
let make = (~title) => {
  let (checked, setChecked) = React.useState(() => false);
  <div
    className="bg-white rounded p-4 shadow-xs cursor-pointer"
    onClick={e => {
      ReactEvent.Mouse.preventDefault(e);
      setChecked(prev => !prev);
    }}>
    <input type_="checkbox" checked />
    <span className="ml-2 text-lg text-gray-700 select-none"> title </span>
  </div>;
};
