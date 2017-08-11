// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_NODE_ND4J_GRAPH_H_
#define FLATBUFFERS_GENERATED_NODE_ND4J_GRAPH_H_

#include "flatbuffers/flatbuffers.h"

namespace nd4j {
namespace graph {

struct Variable;

struct Operands;

struct Node;

enum OpType {
  OpType_TRANSFORM = 0,
  OpType_ACCUMULATION = 1,
  OpType_INDEX_ACCUMULATION = 2,
  OpType_SCALAR = 3,
  OpType_BROADCAST = 4,
  OpType_MIN = OpType_TRANSFORM,
  OpType_MAX = OpType_BROADCAST
};

inline OpType (&EnumValuesOpType())[5] {
  static OpType values[] = {
    OpType_TRANSFORM,
    OpType_ACCUMULATION,
    OpType_INDEX_ACCUMULATION,
    OpType_SCALAR,
    OpType_BROADCAST
  };
  return values;
}

inline const char **EnumNamesOpType() {
  static const char *names[] = {
    "TRANSFORM",
    "ACCUMULATION",
    "INDEX_ACCUMULATION",
    "SCALAR",
    "BROADCAST",
    nullptr
  };
  return names;
}

inline const char *EnumNameOpType(OpType e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesOpType()[index];
}

MANUALLY_ALIGNED_STRUCT(8) Operands FLATBUFFERS_FINAL_CLASS {
 private:
  uint64_t x_;
  uint64_t z_;
  uint64_t y_;

 public:
  Operands() {
    memset(this, 0, sizeof(Operands));
  }
  Operands(const Operands &_o) {
    memcpy(this, &_o, sizeof(Operands));
  }
  Operands(uint64_t _x, uint64_t _z, uint64_t _y)
      : x_(flatbuffers::EndianScalar(_x)),
        z_(flatbuffers::EndianScalar(_z)),
        y_(flatbuffers::EndianScalar(_y)) {
  }
  uint64_t x() const {
    return flatbuffers::EndianScalar(x_);
  }
  uint64_t z() const {
    return flatbuffers::EndianScalar(z_);
  }
  uint64_t y() const {
    return flatbuffers::EndianScalar(y_);
  }
};
STRUCT_END(Operands, 24);

struct Variable FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ID = 4,
    VT_NAME = 6,
    VT_SHAPE = 8,
    VT_VALUES = 10
  };
  uint64_t id() const {
    return GetField<uint64_t>(VT_ID, 0);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::Vector<int32_t> *shape() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_SHAPE);
  }
  const flatbuffers::Vector<float> *values() const {
    return GetPointer<const flatbuffers::Vector<float> *>(VT_VALUES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_ID) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyOffset(verifier, VT_SHAPE) &&
           verifier.Verify(shape()) &&
           VerifyOffset(verifier, VT_VALUES) &&
           verifier.Verify(values()) &&
           verifier.EndTable();
  }
};

struct VariableBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(uint64_t id) {
    fbb_.AddElement<uint64_t>(Variable::VT_ID, id, 0);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Variable::VT_NAME, name);
  }
  void add_shape(flatbuffers::Offset<flatbuffers::Vector<int32_t>> shape) {
    fbb_.AddOffset(Variable::VT_SHAPE, shape);
  }
  void add_values(flatbuffers::Offset<flatbuffers::Vector<float>> values) {
    fbb_.AddOffset(Variable::VT_VALUES, values);
  }
  VariableBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VariableBuilder &operator=(const VariableBuilder &);
  flatbuffers::Offset<Variable> Finish() {
    const auto end = fbb_.EndTable(start_, 4);
    auto o = flatbuffers::Offset<Variable>(end);
    return o;
  }
};

inline flatbuffers::Offset<Variable> CreateVariable(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t id = 0,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> shape = 0,
    flatbuffers::Offset<flatbuffers::Vector<float>> values = 0) {
  VariableBuilder builder_(_fbb);
  builder_.add_id(id);
  builder_.add_values(values);
  builder_.add_shape(shape);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Variable> CreateVariableDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t id = 0,
    const char *name = nullptr,
    const std::vector<int32_t> *shape = nullptr,
    const std::vector<float> *values = nullptr) {
  return nd4j::graph::CreateVariable(
      _fbb,
      id,
      name ? _fbb.CreateString(name) : 0,
      shape ? _fbb.CreateVector<int32_t>(*shape) : 0,
      values ? _fbb.CreateVector<float>(*values) : 0);
}

struct Node FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TYPE = 4,
    VT_OPNUM = 6,
    VT_NAME = 8,
    VT_OPERANDS = 10,
    VT_INPUT = 12
  };
  OpType type() const {
    return static_cast<OpType>(GetField<int8_t>(VT_TYPE, 0));
  }
  int16_t opNum() const {
    return GetField<int16_t>(VT_OPNUM, 0);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const Operands *operands() const {
    return GetStruct<const Operands *>(VT_OPERANDS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Node>> *input() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Node>> *>(VT_INPUT);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_TYPE) &&
           VerifyField<int16_t>(verifier, VT_OPNUM) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<Operands>(verifier, VT_OPERANDS) &&
           VerifyOffset(verifier, VT_INPUT) &&
           verifier.Verify(input()) &&
           verifier.VerifyVectorOfTables(input()) &&
           verifier.EndTable();
  }
};

struct NodeBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(OpType type) {
    fbb_.AddElement<int8_t>(Node::VT_TYPE, static_cast<int8_t>(type), 0);
  }
  void add_opNum(int16_t opNum) {
    fbb_.AddElement<int16_t>(Node::VT_OPNUM, opNum, 0);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Node::VT_NAME, name);
  }
  void add_operands(const Operands *operands) {
    fbb_.AddStruct(Node::VT_OPERANDS, operands);
  }
  void add_input(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Node>>> input) {
    fbb_.AddOffset(Node::VT_INPUT, input);
  }
  NodeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NodeBuilder &operator=(const NodeBuilder &);
  flatbuffers::Offset<Node> Finish() {
    const auto end = fbb_.EndTable(start_, 5);
    auto o = flatbuffers::Offset<Node>(end);
    return o;
  }
};

inline flatbuffers::Offset<Node> CreateNode(
    flatbuffers::FlatBufferBuilder &_fbb,
    OpType type = OpType_TRANSFORM,
    int16_t opNum = 0,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    const Operands *operands = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Node>>> input = 0) {
  NodeBuilder builder_(_fbb);
  builder_.add_input(input);
  builder_.add_operands(operands);
  builder_.add_name(name);
  builder_.add_opNum(opNum);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Node> CreateNodeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    OpType type = OpType_TRANSFORM,
    int16_t opNum = 0,
    const char *name = nullptr,
    const Operands *operands = 0,
    const std::vector<flatbuffers::Offset<Node>> *input = nullptr) {
  return nd4j::graph::CreateNode(
      _fbb,
      type,
      opNum,
      name ? _fbb.CreateString(name) : 0,
      operands,
      input ? _fbb.CreateVector<flatbuffers::Offset<Node>>(*input) : 0);
}

inline const nd4j::graph::Node *GetNode(const void *buf) {
  return flatbuffers::GetRoot<nd4j::graph::Node>(buf);
}

inline bool VerifyNodeBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<nd4j::graph::Node>(nullptr);
}

inline void FinishNodeBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<nd4j::graph::Node> root) {
  fbb.Finish(root);
}

}  // namespace graph
}  // namespace nd4j

#endif  // FLATBUFFERS_GENERATED_NODE_ND4J_GRAPH_H_
