macro aif {
  case {
    match {
      $(cond)
    }
    template {
      typeof($(cond)) it = $(cond);
      if(it)
    }
  }
}
