macro var {
  case {
    match {
      $(name) = $(val);
    }
    template {
      typeof($(val)) $(name) = $(val);
    }
  }
}
