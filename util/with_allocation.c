macro with_allocation {
  case {
    match {
      ($(ptr-name ident), $(type), $(size))
        $(body block)
    }
    template {
      {
        $(type)* $(ptr-name) = malloc(sizeof($(type)) * $(size));
        if($(ptr-name))
          $(body)
        free($(ptr-name));
      }
    }
  }
  case {
    match {
      ($(ptr-name ident), $(type))
        $(body block)
    }
    template {
      with_allocation($(ptr-name), $(type), 1)
        $(body)
    }
  }
}
