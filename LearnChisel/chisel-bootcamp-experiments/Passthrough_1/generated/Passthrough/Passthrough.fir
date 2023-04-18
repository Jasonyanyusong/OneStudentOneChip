circuit Passthrough :
  module Passthrough :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip in : UInt<4>, out : UInt<4>}

    io.out <= io.in @[Passthrough.scala 12:12]

