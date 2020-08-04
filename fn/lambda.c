macro lambda {
  case {
    match {
      $(args) -> $(ret list) $(body)
    }
    template {
      $(@getsym lambda 0)
    }
    toplevel {
      $(@splice ret) $(@gensym lambda) $(args) $(body)
    }
  }
  case {
    match {
      $(args) -> $(ret) $(body)
    }
    template {
      $(@getsym lambda 0)
    }
    toplevel {
      $(ret) $(@gensym lambda) $(args) $(body)
    }
  }
}
