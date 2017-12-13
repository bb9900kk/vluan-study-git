// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MyProtoJava.proto

package MyTestProtobufJava;

public final class MyTestProtobufJavaMsg {
  private MyTestProtobufJavaMsg() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  public interface SendMyDataTestOrBuilder extends
      // @@protoc_insertion_point(interface_extends:MyTestProtobufJava.SendMyDataTest)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>string name = 1;</code>
     */
    java.lang.String getName();
    /**
     * <code>string name = 1;</code>
     */
    com.google.protobuf.ByteString
        getNameBytes();

    /**
     * <code>int32 id = 2;</code>
     */
    int getId();

    /**
     * <code>float salary1 = 3;</code>
     */
    float getSalary1();

    /**
     * <code>double salary2 = 4;</code>
     */
    double getSalary2();

    /**
     * <code>bytes keyPrivate = 5;</code>
     */
    com.google.protobuf.ByteString getKeyPrivate();
  }
  /**
   * Protobuf type {@code MyTestProtobufJava.SendMyDataTest}
   */
  public  static final class SendMyDataTest extends
      com.google.protobuf.GeneratedMessageV3 implements
      // @@protoc_insertion_point(message_implements:MyTestProtobufJava.SendMyDataTest)
      SendMyDataTestOrBuilder {
  private static final long serialVersionUID = 0L;
    // Use SendMyDataTest.newBuilder() to construct.
    private SendMyDataTest(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
      super(builder);
    }
    private SendMyDataTest() {
      name_ = "";
      id_ = 0;
      salary1_ = 0F;
      salary2_ = 0D;
      keyPrivate_ = com.google.protobuf.ByteString.EMPTY;
    }

    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
    getUnknownFields() {
      return this.unknownFields;
    }
    private SendMyDataTest(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      this();
      if (extensionRegistry == null) {
        throw new java.lang.NullPointerException();
      }
      int mutable_bitField0_ = 0;
      com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder();
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!parseUnknownFieldProto3(
                  input, unknownFields, extensionRegistry, tag)) {
                done = true;
              }
              break;
            }
            case 10: {
              java.lang.String s = input.readStringRequireUtf8();

              name_ = s;
              break;
            }
            case 16: {

              id_ = input.readInt32();
              break;
            }
            case 29: {

              salary1_ = input.readFloat();
              break;
            }
            case 33: {

              salary2_ = input.readDouble();
              break;
            }
            case 42: {

              keyPrivate_ = input.readBytes();
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e).setUnfinishedMessage(this);
      } finally {
        this.unknownFields = unknownFields.build();
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return MyTestProtobufJava.MyTestProtobufJavaMsg.internal_static_MyTestProtobufJava_SendMyDataTest_descriptor;
    }

    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return MyTestProtobufJava.MyTestProtobufJavaMsg.internal_static_MyTestProtobufJava_SendMyDataTest_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest.class, MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest.Builder.class);
    }

    public static final int NAME_FIELD_NUMBER = 1;
    private volatile java.lang.Object name_;
    /**
     * <code>string name = 1;</code>
     */
    public java.lang.String getName() {
      java.lang.Object ref = name_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        name_ = s;
        return s;
      }
    }
    /**
     * <code>string name = 1;</code>
     */
    public com.google.protobuf.ByteString
        getNameBytes() {
      java.lang.Object ref = name_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        name_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    public static final int ID_FIELD_NUMBER = 2;
    private int id_;
    /**
     * <code>int32 id = 2;</code>
     */
    public int getId() {
      return id_;
    }

    public static final int SALARY1_FIELD_NUMBER = 3;
    private float salary1_;
    /**
     * <code>float salary1 = 3;</code>
     */
    public float getSalary1() {
      return salary1_;
    }

    public static final int SALARY2_FIELD_NUMBER = 4;
    private double salary2_;
    /**
     * <code>double salary2 = 4;</code>
     */
    public double getSalary2() {
      return salary2_;
    }

    public static final int KEYPRIVATE_FIELD_NUMBER = 5;
    private com.google.protobuf.ByteString keyPrivate_;
    /**
     * <code>bytes keyPrivate = 5;</code>
     */
    public com.google.protobuf.ByteString getKeyPrivate() {
      return keyPrivate_;
    }

    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      if (!getNameBytes().isEmpty()) {
        com.google.protobuf.GeneratedMessageV3.writeString(output, 1, name_);
      }
      if (id_ != 0) {
        output.writeInt32(2, id_);
      }
      if (salary1_ != 0F) {
        output.writeFloat(3, salary1_);
      }
      if (salary2_ != 0D) {
        output.writeDouble(4, salary2_);
      }
      if (!keyPrivate_.isEmpty()) {
        output.writeBytes(5, keyPrivate_);
      }
      unknownFields.writeTo(output);
    }

    public int getSerializedSize() {
      int size = memoizedSize;
      if (size != -1) return size;

      size = 0;
      if (!getNameBytes().isEmpty()) {
        size += com.google.protobuf.GeneratedMessageV3.computeStringSize(1, name_);
      }
      if (id_ != 0) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(2, id_);
      }
      if (salary1_ != 0F) {
        size += com.google.protobuf.CodedOutputStream
          .computeFloatSize(3, salary1_);
      }
      if (salary2_ != 0D) {
        size += com.google.protobuf.CodedOutputStream
          .computeDoubleSize(4, salary2_);
      }
      if (!keyPrivate_.isEmpty()) {
        size += com.google.protobuf.CodedOutputStream
          .computeBytesSize(5, keyPrivate_);
      }
      size += unknownFields.getSerializedSize();
      memoizedSize = size;
      return size;
    }

    @java.lang.Override
    public boolean equals(final java.lang.Object obj) {
      if (obj == this) {
       return true;
      }
      if (!(obj instanceof MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest)) {
        return super.equals(obj);
      }
      MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest other = (MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest) obj;

      boolean result = true;
      result = result && getName()
          .equals(other.getName());
      result = result && (getId()
          == other.getId());
      result = result && (
          java.lang.Float.floatToIntBits(getSalary1())
          == java.lang.Float.floatToIntBits(
              other.getSalary1()));
      result = result && (
          java.lang.Double.doubleToLongBits(getSalary2())
          == java.lang.Double.doubleToLongBits(
              other.getSalary2()));
      result = result && getKeyPrivate()
          .equals(other.getKeyPrivate());
      result = result && unknownFields.equals(other.unknownFields);
      return result;
    }

    @java.lang.Override
    public int hashCode() {
      if (memoizedHashCode != 0) {
        return memoizedHashCode;
      }
      int hash = 41;
      hash = (19 * hash) + getDescriptor().hashCode();
      hash = (37 * hash) + NAME_FIELD_NUMBER;
      hash = (53 * hash) + getName().hashCode();
      hash = (37 * hash) + ID_FIELD_NUMBER;
      hash = (53 * hash) + getId();
      hash = (37 * hash) + SALARY1_FIELD_NUMBER;
      hash = (53 * hash) + java.lang.Float.floatToIntBits(
          getSalary1());
      hash = (37 * hash) + SALARY2_FIELD_NUMBER;
      hash = (53 * hash) + com.google.protobuf.Internal.hashLong(
          java.lang.Double.doubleToLongBits(getSalary2()));
      hash = (37 * hash) + KEYPRIVATE_FIELD_NUMBER;
      hash = (53 * hash) + getKeyPrivate().hashCode();
      hash = (29 * hash) + unknownFields.hashCode();
      memoizedHashCode = hash;
      return hash;
    }

    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        java.nio.ByteBuffer data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        java.nio.ByteBuffer data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }

    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder() {
      return DEFAULT_INSTANCE.toBuilder();
    }
    public static Builder newBuilder(MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest prototype) {
      return DEFAULT_INSTANCE.toBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() {
      return this == DEFAULT_INSTANCE
          ? new Builder() : new Builder().mergeFrom(this);
    }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * Protobuf type {@code MyTestProtobufJava.SendMyDataTest}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:MyTestProtobufJava.SendMyDataTest)
        MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTestOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return MyTestProtobufJava.MyTestProtobufJavaMsg.internal_static_MyTestProtobufJava_SendMyDataTest_descriptor;
      }

      protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return MyTestProtobufJava.MyTestProtobufJavaMsg.internal_static_MyTestProtobufJava_SendMyDataTest_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest.class, MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest.Builder.class);
      }

      // Construct using MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessageV3
                .alwaysUseFieldBuilders) {
        }
      }
      public Builder clear() {
        super.clear();
        name_ = "";

        id_ = 0;

        salary1_ = 0F;

        salary2_ = 0D;

        keyPrivate_ = com.google.protobuf.ByteString.EMPTY;

        return this;
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return MyTestProtobufJava.MyTestProtobufJavaMsg.internal_static_MyTestProtobufJava_SendMyDataTest_descriptor;
      }

      public MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest getDefaultInstanceForType() {
        return MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest.getDefaultInstance();
      }

      public MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest build() {
        MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest buildPartial() {
        MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest result = new MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest(this);
        result.name_ = name_;
        result.id_ = id_;
        result.salary1_ = salary1_;
        result.salary2_ = salary2_;
        result.keyPrivate_ = keyPrivate_;
        onBuilt();
        return result;
      }

      public Builder clone() {
        return (Builder) super.clone();
      }
      public Builder setField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          java.lang.Object value) {
        return (Builder) super.setField(field, value);
      }
      public Builder clearField(
          com.google.protobuf.Descriptors.FieldDescriptor field) {
        return (Builder) super.clearField(field);
      }
      public Builder clearOneof(
          com.google.protobuf.Descriptors.OneofDescriptor oneof) {
        return (Builder) super.clearOneof(oneof);
      }
      public Builder setRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          int index, java.lang.Object value) {
        return (Builder) super.setRepeatedField(field, index, value);
      }
      public Builder addRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          java.lang.Object value) {
        return (Builder) super.addRepeatedField(field, value);
      }
      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest) {
          return mergeFrom((MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest other) {
        if (other == MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest.getDefaultInstance()) return this;
        if (!other.getName().isEmpty()) {
          name_ = other.name_;
          onChanged();
        }
        if (other.getId() != 0) {
          setId(other.getId());
        }
        if (other.getSalary1() != 0F) {
          setSalary1(other.getSalary1());
        }
        if (other.getSalary2() != 0D) {
          setSalary2(other.getSalary2());
        }
        if (other.getKeyPrivate() != com.google.protobuf.ByteString.EMPTY) {
          setKeyPrivate(other.getKeyPrivate());
        }
        this.mergeUnknownFields(other.unknownFields);
        onChanged();
        return this;
      }

      public final boolean isInitialized() {
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest) e.getUnfinishedMessage();
          throw e.unwrapIOException();
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }

      private java.lang.Object name_ = "";
      /**
       * <code>string name = 1;</code>
       */
      public java.lang.String getName() {
        java.lang.Object ref = name_;
        if (!(ref instanceof java.lang.String)) {
          com.google.protobuf.ByteString bs =
              (com.google.protobuf.ByteString) ref;
          java.lang.String s = bs.toStringUtf8();
          name_ = s;
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>string name = 1;</code>
       */
      public com.google.protobuf.ByteString
          getNameBytes() {
        java.lang.Object ref = name_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          name_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>string name = 1;</code>
       */
      public Builder setName(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  
        name_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>string name = 1;</code>
       */
      public Builder clearName() {
        
        name_ = getDefaultInstance().getName();
        onChanged();
        return this;
      }
      /**
       * <code>string name = 1;</code>
       */
      public Builder setNameBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  checkByteStringIsUtf8(value);
        
        name_ = value;
        onChanged();
        return this;
      }

      private int id_ ;
      /**
       * <code>int32 id = 2;</code>
       */
      public int getId() {
        return id_;
      }
      /**
       * <code>int32 id = 2;</code>
       */
      public Builder setId(int value) {
        
        id_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>int32 id = 2;</code>
       */
      public Builder clearId() {
        
        id_ = 0;
        onChanged();
        return this;
      }

      private float salary1_ ;
      /**
       * <code>float salary1 = 3;</code>
       */
      public float getSalary1() {
        return salary1_;
      }
      /**
       * <code>float salary1 = 3;</code>
       */
      public Builder setSalary1(float value) {
        
        salary1_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>float salary1 = 3;</code>
       */
      public Builder clearSalary1() {
        
        salary1_ = 0F;
        onChanged();
        return this;
      }

      private double salary2_ ;
      /**
       * <code>double salary2 = 4;</code>
       */
      public double getSalary2() {
        return salary2_;
      }
      /**
       * <code>double salary2 = 4;</code>
       */
      public Builder setSalary2(double value) {
        
        salary2_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>double salary2 = 4;</code>
       */
      public Builder clearSalary2() {
        
        salary2_ = 0D;
        onChanged();
        return this;
      }

      private com.google.protobuf.ByteString keyPrivate_ = com.google.protobuf.ByteString.EMPTY;
      /**
       * <code>bytes keyPrivate = 5;</code>
       */
      public com.google.protobuf.ByteString getKeyPrivate() {
        return keyPrivate_;
      }
      /**
       * <code>bytes keyPrivate = 5;</code>
       */
      public Builder setKeyPrivate(com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  
        keyPrivate_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>bytes keyPrivate = 5;</code>
       */
      public Builder clearKeyPrivate() {
        
        keyPrivate_ = getDefaultInstance().getKeyPrivate();
        onChanged();
        return this;
      }
      public final Builder setUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.setUnknownFieldsProto3(unknownFields);
      }

      public final Builder mergeUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.mergeUnknownFields(unknownFields);
      }


      // @@protoc_insertion_point(builder_scope:MyTestProtobufJava.SendMyDataTest)
    }

    // @@protoc_insertion_point(class_scope:MyTestProtobufJava.SendMyDataTest)
    private static final MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest DEFAULT_INSTANCE;
    static {
      DEFAULT_INSTANCE = new MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest();
    }

    public static MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest getDefaultInstance() {
      return DEFAULT_INSTANCE;
    }

    private static final com.google.protobuf.Parser<SendMyDataTest>
        PARSER = new com.google.protobuf.AbstractParser<SendMyDataTest>() {
      public SendMyDataTest parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new SendMyDataTest(input, extensionRegistry);
      }
    };

    public static com.google.protobuf.Parser<SendMyDataTest> parser() {
      return PARSER;
    }

    @java.lang.Override
    public com.google.protobuf.Parser<SendMyDataTest> getParserForType() {
      return PARSER;
    }

    public MyTestProtobufJava.MyTestProtobufJavaMsg.SendMyDataTest getDefaultInstanceForType() {
      return DEFAULT_INSTANCE;
    }

  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_MyTestProtobufJava_SendMyDataTest_descriptor;
  private static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_MyTestProtobufJava_SendMyDataTest_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\021MyProtoJava.proto\022\022MyTestProtobufJava\"" +
      "`\n\016SendMyDataTest\022\014\n\004name\030\001 \001(\t\022\n\n\002id\030\002 " +
      "\001(\005\022\017\n\007salary1\030\003 \001(\002\022\017\n\007salary2\030\004 \001(\001\022\022\n" +
      "\nkeyPrivate\030\005 \001(\014B+\n\022MyTestProtobufJavaB" +
      "\025MyTestProtobufJavaMsgb\006proto3"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
    internal_static_MyTestProtobufJava_SendMyDataTest_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_MyTestProtobufJava_SendMyDataTest_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_MyTestProtobufJava_SendMyDataTest_descriptor,
        new java.lang.String[] { "Name", "Id", "Salary1", "Salary2", "KeyPrivate", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
