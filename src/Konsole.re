[@bs.val] [@bs.scope "console"]
external tableWithRestrictions: (array('a), array(string)) => unit = "table";
[@bs.val] [@bs.scope "console"] external table: array('a) => unit = "table";
[@bs.val] [@bs.scope "console"]
external assert_: (bool, string) => unit = "assert";
[@bs.val] [@bs.scope "console"]
external assertDict: (bool, Js.Dict.t('a)) => unit = "assert";
