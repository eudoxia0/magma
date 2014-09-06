cmacro_import "lambda.c"

macro delay {
  case {
    match {
      $(expr)
    }
    template {
      lambda () -> typeof($(expr)) { return $(expr); }
    }
  }
}

macro force {
  case {
    match {
      $(expr)
    }
    template {
      $(expr)()
    }
  }
}
