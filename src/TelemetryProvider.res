module Rollbar = {
  type t = {
    error: (string, Js.Exn.t) => unit,
    critical: string => unit,
    warning: string => unit,
    info: string => unit,
    debug: string => unit,
  }
  type config = {
    accessToken: string,
    captureUncaught: bool,
    captureUnhandledExceptions: bool,
  }
  @new @module external make: config => t = "rollbar"
}

type context = {rollbar: Rollbar.t}
let loadTelemetry = () =>
  Config.isDev
    ? {
        rollbar: {
          error: (_s, _e) => (),
          critical: _s => (),
          warning: _s => (),
          info: _s => (),
          debug: _s => (),
        },
      }
    : {
        rollbar: Rollbar.make({
          accessToken: Config.rollbarToken,
          captureUncaught: true,
          captureUnhandledExceptions: true,
        }),
      }
let context = React.createContext(loadTelemetry())

let make = React.Context.provider(context)
let makeProps = (~value, ~children, ()) =>
  {
    "value": value,
    "children": children,
  }
