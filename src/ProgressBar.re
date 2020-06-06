let str = React.string;

[@react.component]
let make = (~percent: int) => {
  let percentString = string_of_int(percent) ++ "%";
  let style = ReactDOMRe.Style.make(~width=percentString, ());
  <div className="shadow w-full bg-gray-300">
    <div
      className="bg-blue-500 text-xs leading-none py-1 text-center text-white"
      style>
      {percentString |> str}
    </div>
  </div>;
};
