open Haz3lcore;
open ExplainThisForm;
open Example;

let filter = (~p_id: Id.t, ~body_id: Id.t): Simple.t => {
  group_id: Filter,
  form_id: Filter,
  abstract:
    Simple.mk_2(("p", p_id), ("e_body", body_id), (p', e_body') =>
      [mk_filter([[space(), p', space()]]), linebreak(), e_body']
    ),
  explanation:
    Printf.sprintf(
      "Stepper filter. It will control how the stepper behaves in the [*body*](%s) according to the [*pattern*](%s).",
      body_id |> Id.to_string,
      p_id |> Id.to_string,
    ),
  examples: [
    {
      sub_id: FilterEval,
      term:
        mk_example(
          "debug eval($e) in\ndebug stop($v + $v) in\n1 + 2 + 3 + 4",
        ),
      message: "Here `eval($e)` means we want to skip the evaluation of all expression, and `stop($v + $v)` means we want to stop at expression looks like `$v + $v`. In combination, this means we want to evaluation all expression but anything looks like `$v + $v`",
    },
  ],
};

let unquote = (~sel_id: Id.t): Simple.t => {
  group_id: FilterSelector,
  form_id: FilterSelector,
  abstract: Simple.mk_1(("sel", sel_id), sel' => [mk_unquote([]), sel']),
  explanation:
    Printf.sprintf(
      "Selector expression for a stepper filter pattern. When [*sel*](%s) is 'e', it matches any expression, when [*sel*](%s) is 'v' it only matches values.",
      sel_id |> Id.to_string,
      sel_id |> Id.to_string,
    ),
  examples: [],
};
