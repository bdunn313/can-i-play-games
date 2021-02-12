let str = React.string

type variant =
  | Green
  | Blue
  | Yellow
  | Red

@react.component
let make = (~percent: int, ~variant=Blue) => {
  let percentString = string_of_int(percent) ++ "%"
  let style = ReactDOMRe.Style.make(~width=percentString, ())
  let progressStyle = %tw("text-xs leading-none py-1 text-center text-white")->Cn.append(
    switch variant {
    | Blue => %tw("bg-blue-600")
    | Green => %tw("bg-green-600")
    | Yellow => %tw("bg-yellow-600")
    | Red => %tw("bg-red-600")
    },
  )
  <div className=%tw("bg-gray-400")> <div className=progressStyle style /> </div>
}
